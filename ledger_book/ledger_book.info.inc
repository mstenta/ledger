<?php

/**
 * @file
 * Ledger Book property info
 */

/**
 * Implementations hook_entity_property_info().
 */
function ledger_book_entity_property_info() {
  $info = array();

  // Add meta-data about the book properties.
  $book = &$info['ledger_book']['properties'];

  $book['bid'] = array(
    'type' => 'integer',
    'label' => t('Book ID'),
    'description' => t('The unique ID of the ledger book.'),
    'setter permission' => 'administer ledger',
    'schema field' => 'bid',
  );
  $book['name'] = array(
    'label' => t('Name'),
    'description' => t('The name of the book.'),
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'administer ledger',
    'required' => TRUE,
    'schema field' => 'name',
  );
  $book['owner'] = array(
    'type' => 'user',
    'label' => t('Owner'),
    'description' => t('The user who owns the book.'),
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'administer ledger',
    'required' => TRUE,
    'schema field' => 'uid',
  );

  return $info;
}

