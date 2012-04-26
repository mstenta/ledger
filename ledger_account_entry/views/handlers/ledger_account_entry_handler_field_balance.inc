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

    // Add the account entry aid field, so that we can JOIN the account table in $this->query().
    $this->additional_fields['aid'] = 'aid';

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

    // Join the account table and the account_type table, to determine the fundamental type of this account entry's account.
    $join_account = new views_join();
    $join_account->construct('ledger_account', $this->table_alias, 'aid', 'aid');
    $this->account_table = $this->query->add_relationship('ledger_account', $join_account, 'ledger_account', $this->table_alias);
    $join_account_type = new views_join();
    $join_account_type->construct('ledger_account_type', $this->account_table, 'type', 'type');
    $this->account_type_table = $this->query->ensure_table('ledger_account_type', $this->account_table, $join_account_type);
    $this->account_type_field_alias = $this->query->add_field($this->account_type_table, 'fundamental');

    // Set our own custom variable in the query for storing the table alias of the ledger_account_entry table. This will be used in hook_views_query_alter() to add an extra ORDER BY eid to the query.
    $this->query->ledger_account_entry_balance = array(
      'table_alias' => $this->table_alias,
    );
  }

  // Override the get_value function to reverse the sign, if necessary.
  function get_value($values, $field = NULL) {
    $alias = isset($field) ? $this->aliases[$field] : $this->field_alias;
    if (isset($values->{$alias})) {

      // Pass the value and the account type to the sign reversing function.
      ledger_account_balance_sign_reverse($values->{$alias}, $values->{$this->account_type_field_alias});

      // Return the value.
      return $values->{$alias};
    }
  }
}