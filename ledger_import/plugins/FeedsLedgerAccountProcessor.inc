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
}