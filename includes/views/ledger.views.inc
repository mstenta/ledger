<?php

/**
 * Ledger UI Views data.
 */

/**
 * Implementation of hook_views_data_alter().
 */
function ledger_ui_views_data_alter(&$data) {
  
  /**
   * Accounts
   */
  
  // Replace the account name field handler with one that provides a "Link this field to" option.
  $data['ledger_account']['name']['field']['handler'] = 'ledger_handler_field_ledger_account';
  
  // Add field for account view link.
  $data['ledger_account']['view_account'] = array(
    'field' => array(
      'title' => t('Link'),
      'help' => t('Provide a simple link to the account.'),
      'handler' => 'ledger_handler_field_ledger_account_link',
    ),
  );
  
  // Add field for account edit link.
  $data['ledger_account']['edit_account'] = array(
    'field' => array(
      'title' => t('Edit link'),
      'help' => t('Provide a simple link to edit the account.'),
      'handler' => 'ledger_handler_field_ledger_account_link_edit',
    ),
  );
  
  // Add field for account delete link.
  $data['ledger_account']['delete_account'] = array(
    'field' => array(
      'title' => t('Delete link'),
      'help' => t('Provide a simple link to delete the account.'),
      'handler' => 'ledger_handler_field_ledger_account_link_delete',
    ),
  );
  
  /**
   * Transactions
   */
  
  // Replace the transaction description field handler with one that provides a "Link this field to" option.
  $data['ledger_transaction']['description']['field']['handler'] = 'ledger_handler_field_ledger_transaction';
  
  // Add field for transaction view link.
  $data['ledger_transaction']['view_transaction'] = array(
    'field' => array(
      'title' => t('Link'),
      'help' => t('Provide a simple link to the transaction.'),
      'handler' => 'ledger_handler_field_ledger_transaction_link',
    ),
  );
  
  // Add field for transaction edit link.
  $data['ledger_transaction']['edit_transaction'] = array(
    'field' => array(
      'title' => t('Edit link'),
      'help' => t('Provide a simple link to edit the transaction.'),
      'handler' => 'ledger_handler_field_ledger_transaction_link_edit',
    ),
  );
  
  // Add field for transaction delete link.
  $data['ledger_transaction']['delete_transaction'] = array(
    'field' => array(
      'title' => t('Delete link'),
      'help' => t('Provide a simple link to delete the transaction.'),
      'handler' => 'ledger_handler_field_ledger_transaction_link_delete',
    ),
  );
}