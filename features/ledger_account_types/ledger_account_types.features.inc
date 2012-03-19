<?php
/**
 * @file
 * ledger_account_types.features.inc
 */

/**
 * Implements hook_default_ledger_account_type().
 */
function ledger_account_types_default_ledger_account_type() {
  $items = array();
  $items['assets'] = entity_import('ledger_account_type', '{
    "type" : "assets",
    "label" : "Assets",
    "weight" : "0",
    "data" : null,
    "rdf_mapping" : []
  }');
  $items['capital'] = entity_import('ledger_account_type', '{
    "type" : "capital",
    "label" : "Capital",
    "weight" : "0",
    "data" : null,
    "rdf_mapping" : []
  }');
  $items['expenses'] = entity_import('ledger_account_type', '{
    "type" : "expenses",
    "label" : "Expenses",
    "weight" : "0",
    "data" : null,
    "rdf_mapping" : []
  }');
  $items['income'] = entity_import('ledger_account_type', '{
    "type" : "income",
    "label" : "Income",
    "weight" : "0",
    "data" : null,
    "rdf_mapping" : []
  }');
  $items['liabilities'] = entity_import('ledger_account_type', '{
    "type" : "liabilities",
    "label" : "Liabilities",
    "weight" : "0",
    "data" : null,
    "rdf_mapping" : []
  }');
  return $items;
}
