<?php

/**
 * Views for the default ledger Transaction UI.
 */

/**
 * Implements hook_views_default_views().
 */
function ledger_transaction_ui_views_default_views() {
  $views = array();
  
  /**
   * Begin ledger_transactions view.
   */
  $view = new view;
  $view->name = 'ledger_transactions';
  $view->description = 'View of ledger transactions.';
  $view->tag = 'ledger';
  $view->base_table = 'ledger_transaction';
  $view->human_name = 'Ledger Transactions';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Ledger Transactions';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer ledger';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Transactions per page';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '50, 100, 500, 1000';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 1;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'tid' => 'tid',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'tid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No transactions have been created yet.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Field: Transaction: Timestamp */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'ledger_transaction';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['external'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['timestamp']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['timestamp']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['html'] = 0;
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['timestamp']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['timestamp']['hide_empty'] = 0;
  $handler->display->display_options['fields']['timestamp']['empty_zero'] = 0;
  $handler->display->display_options['fields']['timestamp']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'custom';
  $handler->display->display_options['fields']['timestamp']['custom_date_format'] = 'm/d/Y g:i a';
  /* Field: Transaction: Description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'ledger_transaction';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['description']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['description']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['description']['alter']['external'] = 0;
  $handler->display->display_options['fields']['description']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['description']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['description']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['description']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['description']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['description']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['description']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['description']['alter']['html'] = 0;
  $handler->display->display_options['fields']['description']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['description']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['description']['hide_empty'] = 0;
  $handler->display->display_options['fields']['description']['empty_zero'] = 0;
  $handler->display->display_options['fields']['description']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['description']['link_to_transaction'] = 'view';
  /* Field: Transaction: Ledger Entries */
  $handler->display->display_options['fields']['ledger_transaction_entry']['id'] = 'ledger_transaction_entry';
  $handler->display->display_options['fields']['ledger_transaction_entry']['table'] = 'field_data_ledger_transaction_entry';
  $handler->display->display_options['fields']['ledger_transaction_entry']['field'] = 'ledger_transaction_entry';
  $handler->display->display_options['fields']['ledger_transaction_entry']['label'] = 'Transfers';
  $handler->display->display_options['fields']['ledger_transaction_entry']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['ledger_transaction_entry']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['ledger_transaction_entry']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['ledger_transaction_entry']['alter']['external'] = 0;
  $handler->display->display_options['fields']['ledger_transaction_entry']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['ledger_transaction_entry']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['ledger_transaction_entry']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['ledger_transaction_entry']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['ledger_transaction_entry']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['ledger_transaction_entry']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['ledger_transaction_entry']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['ledger_transaction_entry']['alter']['html'] = 0;
  $handler->display->display_options['fields']['ledger_transaction_entry']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['ledger_transaction_entry']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['ledger_transaction_entry']['hide_empty'] = 0;
  $handler->display->display_options['fields']['ledger_transaction_entry']['empty_zero'] = 0;
  $handler->display->display_options['fields']['ledger_transaction_entry']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['ledger_transaction_entry']['group_rows'] = 1;
  $handler->display->display_options['fields']['ledger_transaction_entry']['delta_offset'] = '0';
  $handler->display->display_options['fields']['ledger_transaction_entry']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['ledger_transaction_entry']['multi_type'] = 'ul';
  $handler->display->display_options['fields']['ledger_transaction_entry']['field_api_classes'] = 0;
  /* Field: Transaction: Operations */
  $handler->display->display_options['fields']['transaction_ops']['id'] = 'transaction_ops';
  $handler->display->display_options['fields']['transaction_ops']['table'] = 'ledger_transaction';
  $handler->display->display_options['fields']['transaction_ops']['field'] = 'transaction_ops';
  $handler->display->display_options['fields']['transaction_ops']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['transaction_ops']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['transaction_ops']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['transaction_ops']['alter']['external'] = 0;
  $handler->display->display_options['fields']['transaction_ops']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['transaction_ops']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['transaction_ops']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['transaction_ops']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['transaction_ops']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['transaction_ops']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['transaction_ops']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['transaction_ops']['alter']['html'] = 0;
  $handler->display->display_options['fields']['transaction_ops']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['transaction_ops']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['transaction_ops']['hide_empty'] = 0;
  $handler->display->display_options['fields']['transaction_ops']['empty_zero'] = 0;
  $handler->display->display_options['fields']['transaction_ops']['hide_alter_empty'] = 0;

  /* Display: All transactions (page) */
  $handler = $view->new_display('page', 'All transactions (page)', 'page');
  $handler->display->display_options['display_description'] = 'Page displaying all transactions.';
  $handler->display->display_options['path'] = 'admin/ledger/transactions/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'List';
  $handler->display->display_options['menu']['weight'] = '-10';
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Transactions';
  $handler->display->display_options['tab_options']['description'] = 'Manage transactions in the ledger.';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';

  /* Display: Transactions by account (page) */
  $handler = $view->new_display('page', 'Transactions by account (page)', 'page_1');
  $handler->display->display_options['display_description'] = 'Page displaying all transactions in a given account.';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No transactions in this account.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Transaction: Ledger Entries (ledger_transaction_entry:aid) */
  $handler->display->display_options['arguments']['ledger_transaction_entry_aid']['id'] = 'ledger_transaction_entry_aid';
  $handler->display->display_options['arguments']['ledger_transaction_entry_aid']['table'] = 'field_data_ledger_transaction_entry';
  $handler->display->display_options['arguments']['ledger_transaction_entry_aid']['field'] = 'ledger_transaction_entry_aid';
  $handler->display->display_options['arguments']['ledger_transaction_entry_aid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['ledger_transaction_entry_aid']['title_enable'] = 1;
  $handler->display->display_options['arguments']['ledger_transaction_entry_aid']['title'] = 'Transactions in %1';
  $handler->display->display_options['arguments']['ledger_transaction_entry_aid']['breadcrumb_enable'] = 1;
  $handler->display->display_options['arguments']['ledger_transaction_entry_aid']['breadcrumb'] = '%1';
  $handler->display->display_options['arguments']['ledger_transaction_entry_aid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['ledger_transaction_entry_aid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['ledger_transaction_entry_aid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['ledger_transaction_entry_aid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['ledger_transaction_entry_aid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['ledger_transaction_entry_aid']['specify_validation'] = 1;
  $handler->display->display_options['arguments']['ledger_transaction_entry_aid']['validate']['type'] = 'php';
  $handler->display->display_options['arguments']['ledger_transaction_entry_aid']['validate_options']['code'] = '// Attempt to load the account object.
  $account = ledger_account_load($argument);

  // If the account exists, return TRUE.
  if ($account) {

    // Set the title used for substitution to the account name.
    $handler->validated_title = ledger_account_title($account);
    return TRUE;
  }

  // If the account doesn\'t exist, return FALSE.
  else {
    return FALSE;
  }';
  $handler->display->display_options['arguments']['ledger_transaction_entry_aid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['ledger_transaction_entry_aid']['not'] = 0;
  $handler->display->display_options['path'] = 'admin/ledger/accounts/%/transactions';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Transactions';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Account';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';
  /**
   * End ledger_transactions view.
   */
  
  $views[$view->name] = $view;
  
  return $views;
}
