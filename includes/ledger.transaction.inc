<?php

/**
 * @file
 * Ledger transaction entity code
 */

/**
 * The class for LedgerTransaction entities.
 */
class LedgerTransaction extends Entity {
  
  public function __construct($values = array()) {
    parent::__construct($values, 'ledger_transaction');
  }
  
  protected function defaultLabel() {
    return t('@description', array('@description' => $this->description));
  }
  
  protected function defaultUri() {
    return array('path' => 'ledger/transactions/' . $this->tid);
  }
}

/**
 * The controller for LedgerTransaction entities
 */
class LedgerTransactionController extends EntityAPIController {
  public function __construct($entityType) {
    parent::__construct($entityType);
  }

  /**
   * Create a transaction - we first set up the values that are specific
   * to our ledger_transaction schema but then also go through the EntityAPIController
   * function.
   * 
   * @param $values
   *   Values passed in.
   *
   * @return
   *   A model object with all default fields initialized.
   */
  public function create(array $values = array()) {
    
    // Add values that are specific to our transaction
    $values += array( 
      'tid' => '',
      'description' => '',
      'value' => 0.00,
      'credit_aid' => '',
      'debit_aid' => '',
      'timestamp' => time(),  // Default to current time
    );
    
    $transaction = parent::create($values);
    return $transaction;
  }
}

/**
 * Access callback for ledger transaction.
 *
 * @todo
 *   Expand this access function to check based on the operation being performed.
 *   Also add ability to check a specific transaction entity.
 *
 * @param $op
 *   The operation being performed. One of 'view', 'update', 'create', 'delete'
 *   or just 'edit' (being the same as 'create' or 'update').
 * @param $transaction
 *   Optionally a specific ledger transaction to check.
 * @param $user
 *   The user to check for. Leave it to NULL to check for the global user.
 * @return boolean
 *   Whether access is allowed or not.
 */
function ledger_transaction_access($op, $transaction = NULL, $user = NULL) {
  return user_access('administer ledger', $user);
}

/**
 * Loads a transaction by ID.
 */
function ledger_transaction_load($tid) {
  $transactions = ledger_transaction_load_multiple(array($tid), array());
  return $transactions ? reset($transactions) : FALSE;
}

/**
 * Loads multiple transactions by ID or based on a set of matching conditions.
 *
 * @see entity_load()
 *
 * @param $transaction_ids
 *   An array of transaction IDs.
 * @param $conditions
 *   An array of conditions on the {ledger_transaction} table in the form
 *     'field' => $value.
 * @param $reset
 *   Whether to reset the internal transaction loading cache.
 *
 * @return
 *   An array of transaction objects indexed by tid.
 */
function ledger_transaction_load_multiple($transaction_ids = array(), $conditions = array(), $reset = FALSE) {
  return entity_load('ledger_transaction', $transaction_ids, $conditions, $reset);
}

/**
 * Returns an initialized transaction object.
 *
 * @return
 *   A transaction object with all default fields initialized.
 */
function ledger_transaction_new($values = array()) {
  return entity_get_controller('ledger_transaction')->create($values);
}