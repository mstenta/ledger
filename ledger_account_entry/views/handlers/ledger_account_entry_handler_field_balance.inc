<?php

/**
 * @file
 * Contains the account entry balance handler.
 */

/**
 * Field handler to provide the account balance at the time of the account entry.
 */
class ledger_account_entry_handler_field_balance extends ledger_handler_field_value {

  // Define options for the handler.
  function option_definition() {
    $options = parent::option_definition();

    // Override the default numerator and denominator column names.
    $options['numerator'] = array('default' => 'balance_num');
    $options['denominator'] = array('default' => 'balance_denom');
    return $options;
  }
}