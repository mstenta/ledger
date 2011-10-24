<?php

/**
 * @file
 * Ledger account entity code
 */

/**
 * The class for LedgerAccount entities.
 */
class LedgerAccount extends Entity {
  
  public function __construct($values = array()) {
    parent::__construct($values, 'ledger_account');
  }
  
  protected function defaultLabel() {
    return t('@name', array('@name' => $this->name));
  }
  
  protected function defaultUri() {
    return array('path' => 'ledger/accounts/' . $this->aid);
  }
}

/**
 * The controller for LedgerAccount entities
 */
class LedgerAccountController extends EntityAPIController {
  public function __construct($entityType) {
    parent::__construct($entityType);
  }

  /**
   * Create an account - we first set up the values that are specific
   * to our ledger_account schema but then also go through the EntityAPIController
   * function.
   * 
   * @param $values
   *   Values passed in.
   *
   * @return
   *   A model object with all default fields initialized.
   */
  public function create(array $values = array()) {
    
    // Add values that are specific to our Model
    $values += array( 
      'aid' => '',
      'pid' => 0,      // 
            // 'is_new' => TRUE,
      'name' => '',
      'description' => '',
      'type' => '',
    );
    
    $account = parent::create($values);
    return $account;
  }
}

/**
 * UI controller.
 */
class LedgerAccountUIController extends EntityDefaultUIController {

  /**
   * Overrides hook_menu() defaults.
   */
  public function hook_menu() {
    $items = parent::hook_menu();
    $items[$this->path]['description'] = 'Manage ledger accounts.';
    return $items;
  }
}

/**
 * Access callback for ledger accounts.
 *
 * @todo
 *   Expand this access function to check based on the operation being performed.
 *   Also add ability to check a specific account entity.
 *
 * @param $op
 *   The operation being performed. One of 'view', 'update', 'create', 'delete'
 *   or just 'edit' (being the same as 'create' or 'update').
 * @param $account
 *   Optionally a specific ledger account to check.
 * @param $user
 *   The user to check for. Leave it to NULL to check for the global user.
 * @return boolean
 *   Whether access is allowed or not.
 */
function ledger_account_access($op, $account = NULL, $user = NULL) {
  return user_access('administer ledger', $user);
}