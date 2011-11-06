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
    return array('path' => 'admin/ledger/accounts/' . $this->aid);
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
    
    // Add values that are specific to our account
    $values += array( 
      'aid' => '',
      'pid' => 0,
      'name' => '',
      'description' => '',
      'type' => '',
    );
    
    $account = parent::create($values);
    return $account;
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

/**
 * Loads an account by ID.
 */
function ledger_account_load($aid) {
  $accounts = ledger_account_load_multiple(array($aid), array());
  return $accounts ? reset($accounts) : FALSE;
}

/**
 * Loads multiple accounts by ID or based on a set of matching conditions.
 *
 * @see entity_load()
 *
 * @param $account_ids
 *   An array of account IDs.
 * @param $conditions
 *   An array of conditions on the {ledger_account} table in the form
 *     'field' => $value.
 * @param $reset
 *   Whether to reset the internal account loading cache.
 *
 * @return
 *   An array of account objects indexed by aid.
 */
function ledger_account_load_multiple($account_ids = array(), $conditions = array(), $reset = FALSE) {
  return entity_load('ledger_account', $account_ids, $conditions, $reset);
}

/**
 * Returns an initialized account object.
 *
 * @return
 *   An account object with all default fields initialized.
 */
function ledger_account_new($values = array()) {
  return entity_get_controller('ledger_account')->create($values);
}