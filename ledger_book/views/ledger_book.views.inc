<?php

/**
 * @file
 * Ledger Book Views data.
 */

/**
 * Implements hook_views_data_alter().
 */
function ledger_book_views_data_alter(&$data) {

  // Put {ledger_book_account} table information in the Ledger Book group.
  $data['ledger_book_account']['table']['group'] = t('Ledger Book');

  // Add table information for {ledger_book_account} to link books and accounts.
  $data['ledger_book_account']['table']['join'] = array(
    'ledger_book' => array(
      'left_field' => 'bid',
      'field' => 'bid',
    ),
    'ledger_account' => array(
      'left_field' => 'aid',
      'field' => 'aid',
    ),
  );

  // Book id.
  $data['ledger_book_account']['bid'] = array(
    'title' => t('Book'),
    'help' => t('Ledger book that contains the account.'),
    'relationship' => array(
      'base' => 'ledger_book',
      'base field' => 'bid',
      'handler' => 'views_handler_relationship',
      'label' => t('Book'),
    ),
  );

  // Account id.
  $data['ledger_book_account']['aid'] = array(
    'title' => t('Account'),
    'help' => t('The account in the book.'),
    'relationship' => array(
      'base' => 'ledger_account',
      'base field' => 'aid',
      'handler' => 'views_handler_relationship',
      'label' => t('Account'),
    ),
  );
}

