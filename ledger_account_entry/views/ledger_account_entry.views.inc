<?php

/**
 * Ledger Account Entry Views data.
 */

/**
 * Implementations hook_views_data_alter().
 */
function ledger_account_entry_views_data_alter(&$data) {
  
  // Replace the ledger_account_entry value field handler with out own extended handler.
  $data['ledger_account_entry']['value']['field']['handler'] = 'ledger_account_entry_handler_field_value';
}