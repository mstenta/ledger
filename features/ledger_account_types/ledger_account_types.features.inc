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
    "fundamental" : "asset",
    "type" : "assets",
    "label" : "Assets",
    "weight" : "0",
    "data" : null,
    "rdf_mapping" : [  ]
  }');
  $items['liabilities'] = entity_import('ledger_account_type', '{
    "fundamental" : "liability",
    "type" : "liabilities",
    "label" : "Liabilities",
    "weight" : "0",
    "data" : null,
    "rdf_mapping" : [  ]
  }');
  $items['equity'] = entity_import('ledger_account_type', '{
    "fundamental" : "equity",
    "type" : "equity",
    "label" : "Equity",
    "weight" : "0",
    "data" : null,
    "rdf_mapping" : [  ]
  }');
  $items['income'] = entity_import('ledger_account_type', '{
    "fundamental" : "income",
    "type" : "income",
    "label" : "Income",
    "weight" : "0",
    "data" : null,
    "rdf_mapping" : [  ]
  }');
  $items['expenses'] = entity_import('ledger_account_type', '{
    "fundamental" : "expense",
    "type" : "expenses",
    "label" : "Expenses",
    "weight" : "0",
    "data" : null,
    "rdf_mapping" : [  ]
  }');
  return $items;
}
