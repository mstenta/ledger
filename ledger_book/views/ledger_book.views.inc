<?php

/**
 * @file
 * Ledger Book Views data.
 */

/**
 * Implements hook_views_plugins().
 */
function ledger_book_views_plugins() {
  return array(
    'argument validator' => array(
      'ledger_book' => array(
        'title' => t('Ledger book'),
        'handler' => 'ledger_book_plugin_argument_validate_book',
      ),
    ),
  );
}

/**
 * Implements hook_views_data_alter().
 */
function ledger_book_views_data_alter(&$data) {

  // Replace the book name field handler with one that provides a "Link this field to" option.
  $data['ledger_book']['name']['field']['handler'] = 'ledger_book_handler_field';

  // Add a field for book view link.
  $data['ledger_book']['view_book'] = array(
    'field' => array(
      'title' => t('Link'),
      'help' => t('Provide a simple link to the book.'),
      'handler' => 'ledger_book_handler_field_link',
    ),
  );

  // Add a field for book edit link.
  $data['ledger_book']['edit_book'] = array(
    'field' => array(
      'title' => t('Edit link'),
      'help' => t('Provide a simple link to edit the book.'),
      'handler' => 'ledger_book_handler_field_link_edit',
    ),
  );

  // Add a field for book delete link.
  $data['ledger_book']['delete_book'] = array(
    'field' => array(
      'title' => t('Delete link'),
      'help' => t('Provide a simple link to delete the book.'),
      'handler' => 'ledger_book_handler_field_link_delete',
    ),
  );

  // Add a field for common book operations. This is just a combination of Edit, and Delete fields above.
  $data['ledger_book']['book_ops'] = array(
    'field' => array(
      'title' => t('Operations'),
      'help' => t('Links to various book operations.'),
      'handler' => 'ledger_book_handler_field_operations',
    ),
  );
}

