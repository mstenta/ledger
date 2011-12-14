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
    // $node = new stdClass();
    // $node->type = $this->config['content_type'];
    // $node->changed = REQUEST_TIME;
    // $node->created = REQUEST_TIME;
    // $node->language = LANGUAGE_NONE;
    // node_object_prepare($node);
    // // Populate properties that are set by node_object_prepare().
    // $node->log = 'Created by FeedsNodeProcessor';
    // $node->uid = $this->config['author'];
    // return $node;
  }
  
  /**
   * Loads an existing account.
   *
   * If the update existing method is not FEEDS_UPDATE_EXISTING, only the account
   * table will be loaded, foregoing the account_load API for better performance.
   */
  protected function entityLoad(FeedsSource $source, $nid) {
    // if ($this->config['update_existing'] == FEEDS_UPDATE_EXISTING) {
    //   $node = node_load($nid, NULL, TRUE);
    // }
    // else {
    //   // We're replacing the existing node. Only save the absolutely necessary.
    //   $node = db_query("SELECT created, nid, vid, type FROM {node} WHERE nid = :nid", array(':nid' => $nid))->fetchObject();
    //   $node->uid = $this->config['author'];
    // }
    // node_object_prepare($node);
    // // Populate properties that are set by node_object_prepare().
    // if ($this->config['update_existing'] == FEEDS_UPDATE_EXISTING) {
    //   $node->log = 'Updated by FeedsNodeProcessor';
    // }
    // else {
    //   $node->log = 'Replaced by FeedsNodeProcessor';
    // }
    // return $node;
  }
  
  /**
   * Save an account.
   */
  public function entitySave($entity) {
    // node_save($entity);
  }
  
  /**
   * Delete a series of accounts.
   */
  protected function entityDeleteMultiple($nids) {
    // node_delete_multiple($nids);
  }
}