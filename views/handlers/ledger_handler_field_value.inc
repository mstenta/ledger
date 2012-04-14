<?php

/**
 * @file
 * Contains the value field handler.
 * This handler can be used by modules that store values in value_num and value_denom fields.
 */
class ledger_handler_field_value extends views_handler_field_numeric {

  // Define options for the handler.
  function option_definition() {
    $options = parent::option_definition();

    // Add option defaults for the numerator and denominator column names.
    $options['numerator'] = array('default' => 'value_num');
    $options['denominator'] = array('default' => 'value_denom');
    return $options;
  }

  // Add fields to the query.
  function query() {

    // Ensure the main table for this field is included.
    $this->ensure_my_table();

    // Formula for calculating the final value, by dividing value by denom.
    $formula = $this->table_alias . '.' . $this->options['numerator'] . ' / ' . $this->table_alias . '.' . $this->options['denominator'];
    $this->field_alias = $this->query->add_field(NULL, $formula, $this->table . '_' . $this->field);
  }
}