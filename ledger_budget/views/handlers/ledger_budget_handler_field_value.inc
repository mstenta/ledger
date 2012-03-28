<?php

/**
 * @file
 * Contains the budget value field handler.
 */

/**
 * Field handler for budget value.
 */
class ledger_budget_handler_field_value extends views_handler_field_numeric {

  // Add fields to the query.
  function query() {

    // Ensure the main table for this field is included.
    $this->ensure_my_table();

    // Formula for calculating the final value, by dividing value by denom.
    $formula = $this->table_alias . '.value_num / ' . $this->table_alias . '.value_denom';
    $this->field_alias = $this->query->add_field(NULL, $formula, $this->table . '_' . $this->field);
  }
}