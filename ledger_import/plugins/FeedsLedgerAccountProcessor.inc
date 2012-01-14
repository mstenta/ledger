<?php

/**
 * @file
 * Class definition of FeedsLedgerAccountProcessor.
 */

/**
 * Creates Ledger Accounts from feed items.
 */
class FeedsLedgerAccountProcessor extends FeedsProcessor {
  
  /**
   * Define entity type.
   */
  public function entityType() {
    return 'ledger_account';
  }
  
  /**
   * Creates a new account in memory and returns it.
   */
  protected function newEntity(FeedsSource $source) {
    $account = ledger_account_new();
    return $account;
  }
  
  /**
   * Loads an existing account.
   *
   * If the update existing method is not FEEDS_UPDATE_EXISTING, a new ledger_account will be created, rather than loading the existing one.
   */
  protected function entityLoad(FeedsSource $source, $aid) {
    if ($this->config['update_existing'] == FEEDS_UPDATE_EXISTING) {
      $account = ledger_account_load($aid);
    }
    else {
      $account = ledger_account_new();
    }
    return $account;
  }
  
  /**
   * Save an account.
   */
  public function entitySave($account) {
    ledger_account_save($account);
  }
  
  /**
   * Delete a series of accounts.
   */
  protected function entityDeleteMultiple($aids) {
    ledger_account_delete_multiple($aids);
  }
  
  /**
   * Declare default configuration.
   */
  public function configDefaults() {
    $config = parent::configDefaults();
    
    // Add a default value for the Account Type Mapping field.
    $config['account_type_mapping'] = '';
    
    return $config;
  }
  
  /**
   * Overrides parent::configForm().
   */
  public function configForm(&$form_state) {
    $form = parent::configForm($form_state);
    
    // Add a field for defining account type mappings
    $form['account_type_mapping'] = array(
      '#type' => 'textarea',
      '#title' => t('Account Type Mapping'),
      '#description' => t('Use this field to define account type mappings. Enter one mapping per line, with the old type name first, followed by a colon (:), and then the machine name of the account type that exists in Ledger. Example: <strong>old:new</strong>'),
      '#default_value' => $this->config['account_type_mapping'],
    );
    
    return $form;
  }
  
  /**
   * Returns an array of account type mappings.
   */
  public function getAccountTypeMappings() {
    
    // Start an empty array to read mappings into.
    $account_type_mapping = array();
    
    // Build the array if it isn't already.
    if (!empty($this->config['account_type_mapping']) && empty($this->config['account_type_mapping_array'])) {
      
      // Break it up into an array of lines
      $account_type_mapping_lines = explode("\n", $this->config['account_type_mapping']);
      
      // Loop through the mapping lines, check their syntax, and add them to the array of mappings.
      if (!empty($account_type_mapping_lines)) {
        foreach ($account_type_mapping_lines as $line) {
          
          // Break the line up into two elements separated by the colon (:).
          $mapping = explode(':', $line);
          
          // If there are two items
          if (count($mapping == 2)) {
            
            // Add it to the array
            $account_type_mapping[trim($mapping[0])] = trim($mapping[1]);
          }
        }
      }
    }
    
    // If the config array is already built, use that.
    else if (!empty($this->config['account_type_mapping_array'])) {
      $account_type_mapping = $this->config['account_type_mapping_array'];
    }
    
    return $account_type_mapping;
  }

  /**
   * Declare possible mapping targets that this processor exposes.
   *
   * @ingroup mappingapi
   *
   * @return
   *   An array of mapping targets. Keys are paths to targets
   *   separated by ->, values are TRUE if target can be unique,
   *   FALSE otherwise.
   */
  public function getMappingTargets() {
    $targets = parent::getMappingTargets();
    $targets += array(
      'aid' => array(
        'name' => t('Account ID'),
        'description' => t('The Account ID to assign to the new account. Must be unique.'),
        'optional_unique' => TRUE,
      ),
      'pid' => array(
        'name' => t('Parent Account ID'),
        'description' => t('The ID of the new account\'s parent account.'),
        'optional_unique' => FALSE,
      ),
      'name' => array(
        'name' => t('Name'),
        'description' => t('The account name.'),
        'optional_unique' => FALSE,
      ),
      'description' => array(
        'name' => t('Description'),
        'description' => t('A description of the account.'),
        'optional_unique' => FALSE,
      ),
      'type' => array(
        'name' => t('Account Type'),
        'description' => t('The type of account.'),
        'optional_unique' => FALSE,
      ),
    );
    return $targets;
  }
  
  /**
   * Set a concrete target element. Invoked from FeedsProcessor::map().
   *
   * @ingroup mappingapi
   */
  public function setTargetElement(FeedsSource $source, $target_item, $target_element, $value) {
    switch ($target_element) {
      
      // Account type
      case 'type':
        
        // Load the list of account types
        $types = ledger_account_type_get_names();
        
        // Load the list of account type mappings from the Processor settings.
        $account_type_mapping = $this->getAccountTypeMappings();
        
        // Check to see if there is an account type mapping defined for this account, and if so translate it.
        if (array_key_exists($value, $account_type_mapping)) {
          $value = $account_type_mapping[$value];
        }
        
        // Check to see if the type exists in the list of existing types.
        if (array_key_exists($value, $types)) {
          $target_item->type = $value;
        }
        
        // If the type does not exist
        else {
          
          // Create an 'unknown' type, if one doesn't already exist.
          if (empty($types['unknown'])) {
            $account_type_unknown = entity_get_controller('ledger_account_type')->create();
            $account_type_unknown->name = 'unknown';
            $account_type_unknown->label = 'Unknown';
            $account_type_unknown->save();
          }
          
          // Report to the user that the type was not found.
          drupal_set_message('The account type "' . $value . '" does not exist in Ledger. The imported account "' . $target_item->name . '" has been set to type: "Unknown"', 'warning');
          
          // Set the type to 'unknown'.
          $target_item->type = 'unknown';
        }
        break;
      
      // Pass anything else to the parent class's setTargetElement().
      default:
        parent::setTargetElement($source, $target_item, $target_element, $value);
        break;
    }
  }
}