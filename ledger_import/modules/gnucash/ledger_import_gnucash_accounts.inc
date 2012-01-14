<?php
$feeds_importer = new stdClass;
$feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
$feeds_importer->api_version = 1;
$feeds_importer->id = 'ledger_import_gnucash_accounts';
$feeds_importer->config = array(
  'name' => 'GnuCash Account Import',
  'description' => 'Imports Accounts from a GnuCash XML file.',
  'fetcher' => array(
    'plugin_key' => 'FeedsFileFetcher',
    'config' => array(
      'allowed_extensions' => 'gnucash xml',
      'direct' => 0,
    ),
  ),
  'parser' => array(
    'plugin_key' => 'FeedsXPathParserXML',
    'config' => array(
      'sources' => array(
        'xpathparser:0' => 'act:id[@type="guid"]',
        'xpathparser:1' => 'act:name',
        'xpathparser:2' => 'act:description',
        'xpathparser:3' => 'act:type',
        'xpathparser:4' => 'act:parent[@type="guid"]',
      ),
      'rawXML' => array(
        'xpathparser:0' => 0,
        'xpathparser:1' => 0,
        'xpathparser:2' => 0,
        'xpathparser:3' => 0,
        'xpathparser:4' => 0,
      ),
      'context' => '//gnc:account',
      'exp' => array(
        'errors' => 0,
        'debug' => array(
          'context' => 0,
          'xpathparser:0' => 0,
          'xpathparser:1' => 0,
          'xpathparser:2' => 0,
          'xpathparser:3' => 0,
          'xpathparser:4' => 0,
        ),
      ),
    ),
  ),
  'processor' => array(
    'plugin_key' => 'FeedsLedgerGnuCashAccountProcessor',
    'config' => array(
      'mappings' => array(
        0 => array(
          'source' => 'xpathparser:0',
          'target' => 'guid',
          'unique' => 1,
        ),
        1 => array(
          'source' => 'xpathparser:1',
          'target' => 'name',
          'unique' => FALSE,
        ),
        2 => array(
          'source' => 'xpathparser:2',
          'target' => 'description',
          'unique' => FALSE,
        ),
        3 => array(
          'source' => 'xpathparser:3',
          'target' => 'type',
          'unique' => FALSE,
        ),
        4 => array(
          'source' => 'xpathparser:4',
          'target' => 'pid',
          'unique' => FALSE,
        ),
      ),
      'update_existing' => '0',
      'input_format' => NULL,
      'account_type_mapping' => 'ASSET:assets
BANK:assets
CASH:assets
CREDIT:liabilities
EQUITY:capital
EXPENSE:expenses
INCOME:income
LIABILITY:liabilities
MUTUAL:assets
PAYABLE:liabilities
RECEIVABLE:assets
STOCK:assets',
    ),
  ),
  'content_type' => '',
  'update' => 0,
  'import_period' => '-1',
  'expire_period' => 3600,
  'import_on_create' => 1,
  'process_in_background' => 0,
);
