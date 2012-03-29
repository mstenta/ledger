<?php

/**
 * @file
 * Contains the value field handler.
 * This handler can be used by modules that store values in value_num and value_denom fields.
 */
class ledger_handler_field_value extends views_handler_field_numeric {

  // Add fields to the query.
  function query() {

    // Ensure the main table for this field is included.
    $this->ensure_my_table();

    // Formula for calculating the final value, by dividing value by denom.
    $formula = $this->table_alias . '.value_num / ' . $this->table_alias . '.value_denom';
    $this->field_alias = $this->query->add_field(NULL, $formula, $this->table . '_' . $this->field);
  }
}