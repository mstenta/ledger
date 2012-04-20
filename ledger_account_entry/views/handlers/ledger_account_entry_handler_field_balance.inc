<?php

/**
 * @file
 * Contains the account entry balance handler.
 */

/**
 * Field handler to provide the account balance at the time of the account entry.
 */
class ledger_account_entry_handler_field_balance extends ledger_handler_field_value {

  function construct() {
    
    // Inherit the parent's construction.
    parent::construct();
  
    // Add the account entry id field, so that we can sort by it in hook_views_query_alter().
    $this->additional_fields['eid'] = 'eid';
  }

  // Define options for the handler.
  function option_definition() {
    $options = parent::option_definition();

    // Override the default numerator and denominator column names.
    $options['numerator'] = array('default' => 'balance_num');
    $options['denominator'] = array('default' => 'balance_denom');
    return $options;
  }

  // Sort the results by account entry ID.
  function query() {

    // Execute the parent class's query() method.
    parent::query();

    // Set our own custom variable in the query for storing the table alias of the ledger_account_entry table. This will be used in hook_views_query_alter() to add an extra ORDER BY eid to the query.
    $this->query->ledger_account_entry_balance = array(
      'table_alias' => $this->table_alias,
    );
  }
}