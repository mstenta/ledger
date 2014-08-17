<?php
/**
 * @file
 * ledger_account.features.inc
 */

/**
 * Implements hook_default_ledger_account_type().
 */
function ledger_account_default_ledger_account_type() {
  $items = array();
  $items['assets'] = entity_import('ledger_account_type', '{ "fundamental" : "asset", "type" : "assets", "label" : "Assets" }');
  $items['equity'] = entity_import('ledger_account_type', '{ "fundamental" : "equity", "type" : "equity", "label" : "Equity" }');
  $items['expenses'] = entity_import('ledger_account_type', '{ "fundamental" : "expense", "type" : "expenses", "label" : "Expenses" }');
  $items['income'] = entity_import('ledger_account_type', '{ "fundamental" : "income", "type" : "income", "label" : "Income" }');
  $items['liabilities'] = entity_import('ledger_account_type', '{ "fundamental" : "liability", "type" : "liabilities", "label" : "Liabilities" }');
  return $items;
}
