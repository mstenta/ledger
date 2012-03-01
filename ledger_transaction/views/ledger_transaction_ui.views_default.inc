<?php

/**
 * @file
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
    'timestamp' => 'timestamp',
    'description' => 'description',
    'value' => 'value',
    'value_1' => 'value_1',
    'transaction_ops' => 'transaction_ops',
  );
  $handler->display->display_options['style_options']['default'] = 'timestamp';
  $handler->display->display_options['style_options']['info'] = array(
    'timestamp' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
    ),
    'description' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'value' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'value_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'transaction_ops' => array(
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['order'] = 'desc';
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
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Transaction: Account entry */
  $handler->display->display_options['relationships']['ledger_account_entry_tid']['id'] = 'ledger_account_entry_tid';
  $handler->display->display_options['relationships']['ledger_account_entry_tid']['table'] = 'ledger_transaction';
  $handler->display->display_options['relationships']['ledger_account_entry_tid']['field'] = 'ledger_account_entry_tid';
  $handler->display->display_options['relationships']['ledger_account_entry_tid']['required'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  /* Field: Account entry: Value */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'ledger_account_entry';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['relationship'] = 'ledger_account_entry_tid';
  $handler->display->display_options['fields']['value']['label'] = 'Increase';
  $handler->display->display_options['fields']['value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['value']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['value']['alter']['external'] = 0;
  $handler->display->display_options['fields']['value']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['value']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['value']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['value']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['value']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['value']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['value']['set_precision'] = 1;
  $handler->display->display_options['fields']['value']['precision'] = '2';
  $handler->display->display_options['fields']['value']['format_plural'] = 0;
  $handler->display->display_options['fields']['value']['format'] = 'increase';
  /* Field: Account entry: Value */
  $handler->display->display_options['fields']['value_1']['id'] = 'value_1';
  $handler->display->display_options['fields']['value_1']['table'] = 'ledger_account_entry';
  $handler->display->display_options['fields']['value_1']['field'] = 'value';
  $handler->display->display_options['fields']['value_1']['relationship'] = 'ledger_account_entry_tid';
  $handler->display->display_options['fields']['value_1']['label'] = 'Decrease';
  $handler->display->display_options['fields']['value_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['value_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['value_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['value_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['value_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['value_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['value_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['value_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['value_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['value_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['value_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['value_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['value_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['value_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['value_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['value_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['value_1']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['value_1']['set_precision'] = 1;
  $handler->display->display_options['fields']['value_1']['precision'] = '2';
  $handler->display->display_options['fields']['value_1']['format_plural'] = 0;
  $handler->display->display_options['fields']['value_1']['format'] = 'decrease';
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
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Account entry: Account aid */
  $handler->display->display_options['arguments']['account']['id'] = 'account';
  $handler->display->display_options['arguments']['account']['table'] = 'ledger_account_entry';
  $handler->display->display_options['arguments']['account']['field'] = 'account';
  $handler->display->display_options['arguments']['account']['relationship'] = 'ledger_account_entry_tid';
  $handler->display->display_options['arguments']['account']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['account']['title_enable'] = 1;
  $handler->display->display_options['arguments']['account']['title'] = 'Transactions in %1';
  $handler->display->display_options['arguments']['account']['breadcrumb_enable'] = 1;
  $handler->display->display_options['arguments']['account']['breadcrumb'] = '%1';
  $handler->display->display_options['arguments']['account']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['account']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['account']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['account']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['account']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['account']['specify_validation'] = 1;
  $handler->display->display_options['arguments']['account']['validate']['type'] = 'php';
  $handler->display->display_options['arguments']['account']['validate_options']['code'] = '// Attempt to load the account object.
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
  $handler->display->display_options['arguments']['account']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['account']['not'] = 0;
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