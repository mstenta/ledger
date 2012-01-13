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
   * Get mappings.
   */
  public function getMappings() {
    return isset($this->config['mappings']) ? $this->config['mappings'] : array();
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
        
        // Check to see if the type exists in the list of existing types.
        if (array_key_exists($type, $types)) {
          $target_element->type = $type;
        }
        
        // If the type does not exist
        else {
          
          // Create an 'unknown' type, if one doesn't already exist.
          if (!array_key_exists('unknown', $types)) {
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