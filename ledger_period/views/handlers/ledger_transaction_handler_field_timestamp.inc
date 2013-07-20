<?php

/**
 * @file
 * Contains the transaction timestamp field handler.
 */

/**
 * Field handler for transaction timestamps, for automatically sorting by account entry id also.
 */
class ledger_transaction_handler_field_timestamp extends views_handler_field_date {

  /**
   * Called to determine what to tell the clicksorter.
   */
  function click_sort($order) {

    // First apply the parent click sort.
    parent::click_sort($order);

    // If the account entry balance field is present, also sort by account entry id.
    // We assume that the {ledger_account_entry} table is present if the balance field is.
    if (isset($this->field_alias) && isset($this->query->ledger_balance_eid_field_alias)) {
      $params = $this->options['group_type'] != 'group' ? array('function' => $this->options['group_type']) : array();
      $this->query->add_orderby(NULL, NULL, $order, $this->query->ledger_balance_eid_field_alias, $params);
    }
  }
}

