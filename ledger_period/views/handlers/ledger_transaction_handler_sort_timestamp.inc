<?php

/**
 * @file
 * Contains the transaction timestamp sort handler.
 */

/**
 * Sort handler for transaction timestamps, for automatically sorting by account entry id also.
 */
class ledger_transaction_handler_sort_timestamp extends views_handler_sort_date {

  /**
   * Called to add the sort to a query.
   */
  function query() {

    // Call the parent query method.
    parent::query();

    // If the account entry balance field is present, also sort by account entry id.
    // We assume that the {ledger_account_entry} table is present if the balance field is.
    if (isset($this->query->ledger_account_entry_balance_eid_field_alias)) {
      $params = $this->options['group_type'] != 'group' ? array('function' => $this->options['group_type']) : array();
      $this->query->add_orderby(NULL, NULL, $this->options['order'], $this->query->ledger_account_entry_balance_eid_field_alias, $params);
    }
  }
}

