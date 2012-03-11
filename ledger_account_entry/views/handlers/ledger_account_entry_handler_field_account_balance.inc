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
  
  // Add fields to the query.
  function query() {

    // Ensure the main table for this field is included.
    $this->ensure_my_table();

    // Include additional fields (like account id defined in $this->construct())
    $this->add_additional_fields();
  }
  
  // Render the field.
  function render($values) {

    // Load the account entry id and account id values.
    // $eid = $this->get_value($values, 'eid');
    // $aid = $this->get_value($values, 'aid');
    $eid = $values->ledger_account_entry_ledger_transaction_eid;
    $aid = $values->ledger_account_entry_ledger_transaction_aid;

    // Perform a query to calculate the total of all the transactions on this account up to and including this one.
    /**
     * @todo
     *   Find a better way of doing this.
     *   This causes an additional query to be executed every time this field is used on the View.
     */
    $balance = db_query('SELECT SUM(e.value)
      FROM {ledger_account_entry} e
      LEFT JOIN {ledger_transaction} t ON e.tid=t.tid
      WHERE e.aid=:aid
        AND t.timestamp <= (
          SELECT timestamp
          FROM {ledger_transaction} t
          LEFT JOIN {ledger_account_entry} e ON t.tid=e.tid
          WHERE e.eid=:eid);
    ', array(':aid' => $aid, ':eid' => $eid))->fetchField();

    // Pass it to the parent render function and return the result.
    // return parent::render($balance);
    return $balance;
  }
}