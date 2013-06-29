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

    // Add the account entry id field, so that we can join to the {account_entry}
    // table in $this::query().
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

    // Join the {ledger_account_entry} table to the {ledger_account_entry_balance} table.
    $join_account_entry = new views_join();
    $join_account_entry->construct('ledger_account_entry', $this->table_alias, 'eid', 'eid');
    $this->table_alias_account_entry = $this->query->add_relationship('ledger_account_entry', $join_account_entry, 'ledger_account_entry');

    // Join the {ledger_account} table to the {ledger_account_entry} table.
    $join_account = new views_join();
    $join_account->construct('ledger_account', $this->table_alias_account_entry, 'aid', 'aid');
    $this->table_alias_account = $this->query->add_relationship('ledger_account', $join_account, 'ledger_account', $this->table_alias_account_entry);

    // Join the {ledger_account_type} table to the {ledger_account} table, and fundamental account type..
    $join_account_type = new views_join();
    $join_account_type->construct('ledger_account_type', $this->table_alias_account, 'type', 'type');
    $this->table_alias_account_type = $this->query->ensure_table('ledger_account_type', $this->table_alias_account, $join_account_type);
    $this->account_type_field_alias = $this->query->add_field($this->table_alias_account_type, 'fundamental');

    // Set a custom variable in the query to hold the eid field alias.
    // This will be used in the ledger_transaction_handler_sort_timestamp class to add an additional sort by eid to the View.
    $this->query->ledger_account_entry_balance_eid_field_alias = $this->aliases['eid'];
  }

  // Override the get_value function to reverse the sign, if necessary.
  function get_value($values, $field = NULL) {
    $alias = isset($field) ? $this->aliases[$field] : $this->field_alias;
    if (isset($values->{$alias})) {

      // Pass the value and the account type to the sign reversing function.
      ledger_period_sign_reverse($values->{$alias}, $values->{$this->account_type_field_alias});

      // Return the value.
      return $values->{$alias};
    }
  }
}

