<?php

/**
 * @file
 * Contains the account balance field handler.
 */

/**
 * Field handler to provide an account's current balance.
 */
class ledger_account_handler_field_balance extends views_handler_field_numeric {

  function construct() {
    
    // Inherit the parent's construction.
    parent::construct();

    // Add the account id field.
    $this->additional_fields['aid'] = 'aid';
  }

  // Add fields to the query.
  function query() {

    // Ensure the main table for this field is included.
    $this->ensure_my_table();

    // Include additional fields.
    $this->add_additional_fields();

    // Join the account_type table, to determine the fundamental account type.
    $join = new views_join();
    $join->construct('ledger_account_type', $this->table_alias, 'type', 'type');
    $this->account_type_table = $this->query->ensure_table('ledger_account_type', $this->relationship, $join);
    $this->account_type_field_alias = $this->query->add_field($this->account_type_table, 'fundamental');

    // Build a subquery that calculates the account's balance.
    $subquery = db_select('ledger_account_entry', 'e');
    $subquery->addExpression('SUM(e.value_num / e.value_denom)', 'account_balance');
    $subquery->where("e.aid = $this->table_alias.aid");

    // Add the subquery as the field.
    $this->field_alias = $this->query->add_field(NULL, '(' . $subquery . ')', $this->table . '_' . $this->field);
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