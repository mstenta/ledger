<?php

/**
 * @file
 * Ledger Period Views hooks.
 */

/**
 * Implements hook_views_data_alter().
 */
function ledger_period_views_data_alter(&$data) {

  // Override the balance field handler.
  $data['field_data_ledger_balance']['ledger_balance']['field']['handler'] = 'ledger_handler_field_balance';

  // Override the default transaction timestamp field and sort handler to also sort by account entry id when an account entry balance is present.
  $data['ledger_transaction']['timestamp']['field']['handler'] = 'ledger_transaction_handler_field_timestamp';
  $data['ledger_transaction']['timestamp']['sort']['handler'] = 'ledger_transaction_handler_sort_timestamp';
}

