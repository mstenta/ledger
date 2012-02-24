<?php

/**
 * @file
 * Class definition of FeedsLedgerTransactionProcessor.
 */

/**
 * Creates Ledger Transactions from feed items.
 */
class FeedsLedgerTransactionProcessor extends FeedsProcessor {

  /**
   * Define entity type.
   */
  public function entityType() {
    return 'ledger_transaction';
  }
  
  /**
   * Creates a new transaction in memory and returns it.
   */
  protected function newEntity(FeedsSource $source) {
    $transaction = ledger_transaction_new();
    return $transaction;
  }
  
  /**
   * Loads an existing transaction.
   *
   * If the update existing method is not FEEDS_UPDATE_EXISTING, a new ledger_transaction will be created, rather than loading the existing one.
   */
  protected function entityLoad(FeedsSource $source, $tid) {
    if ($this->config['update_existing'] == FEEDS_UPDATE_EXISTING) {
      $transaction = ledger_transaction_load($tid);
    }
    else {
      $transaction = ledger_transaction_new();
    }
    return $transaction;
  }
  
  /**
   * Save a transaction.
   */
  public function entitySave($transaction) {
    ledger_transaction_save($transaction);
  }
  
  /**
   * Delete a series of transactions.
   */
  protected function entityDeleteMultiple($tids) {
    
    // Delete all account entries associated with the transanctions.
    if (!empty($tids)) {
      db_query('DELETE FROM {ledger_account_entry} WHERE tid IN (' . implode(',', $tids) . ')');
    }
    
    // Delete the transactions
    ledger_transaction_delete_multiple($tids);
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
        'name' => t('Transaction ID'),
        'description' => t('The Account ID to assign to the new account. Must be unique.'),
        'optional_unique' => TRUE,
      ),
      'description' => array(
        'name' => t('Description'),
        'description' => t('A description of the transaction.'),
        'optional_unique' => FALSE,
      ),
      'timestamp' => array(
        'name' => t('Transaction timestamp'),
        'description' => t('The timestamp of the transaction.'),
        'optional_unique' => FALSE,
      ),
      'entries' => array(
        'name' => t('Account entries'),
        'description' => t('The inidividual account entries associated with the transaction.'),
        'optional_unique' => FALSE,
      ),
    );
    return $targets;
  }
}