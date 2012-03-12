<?php

/**
 * @file
 * Contains the account entry running balance handler.
 */

/**
 * Field handler to provide a running account balance for an account entry.
 */
class ledger_account_entry_handler_field_account_balance extends views_handler_field_numeric {

  // Construct the handler.
  function construct() {

    // Inherit the parent's construction.
    parent::construct();

    // Add the account entry id and the account id fields.
    $this->additional_fields['eid'] = 'eid';
    $this->additional_fields['aid'] = 'aid';
  }

  // Override the default query() method.
  function query() {

    // Ensure the main table for this field is included.
    $this->ensure_my_table();

    // Include additional fields.
    $this->add_additional_fields();

    // Join the 'ledger_transaction' table to this table via tid
    $join = new views_join();
    $join->construct('ledger_transaction', $this->table_alias, 'tid', 'tid');

    // Ensure the transaction table is included in the query.
    $this->transaction_table = $this->query->ensure_table('ledger_transaction', $this->relationship, $join);

    // Build a Drupal query object to pass in.
    $subquery = db_select('ledger_account_entry', 'e');
    $subquery->addExpression('SUM(e.value)', 'account_balance');
    $subquery->join('ledger_transaction', 't', 'e.tid = t.tid');
    $subquery->where("e.aid = $this->table_alias.aid");
    $subquery->where("t.timestamp <= $this->transaction_table.timestamp");

    // Add the running account balance field.
    $this->field_alias = $this->query->add_field(NULL, '(' . $subquery . ')', $this->table_alias . '_' . $this->field);
  }
}