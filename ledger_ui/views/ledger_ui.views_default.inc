<?php

/**
 * Views for the default ledger UI.
 */

/**
 * Implements hook_views_default_views().
 */
function ledger_ui_views_default_views() {
  $views = array();
  
  /**
   * Begin ledger_accounts view.
   */
  $view = new view;
  $view->name = 'ledger_accounts';
  $view->description = 'View of all Ledger Accounts';
  $view->tag = 'ledger';
  $view->base_table = 'ledger_account';
  $view->human_name = 'Ledger Accounts';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Ledger Accounts';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer ledger';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Accounts per page';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '10, 50, 100, 200';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'aid' => 'aid',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'aid' => array(
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
  $handler->display->display_options['empty']['area']['content'] = 'No accounts have been created yet.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Field: Ledger Account: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'ledger_account';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 0;
  /* Field: Ledger Account: Description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'ledger_account';
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
  /* Field: Ledger Account: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'ledger_account';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['type']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['type']['hide_alter_empty'] = 0;
  /* Field: Ledger Account: Pid */
  $handler->display->display_options['fields']['pid']['id'] = 'pid';
  $handler->display->display_options['fields']['pid']['table'] = 'ledger_account';
  $handler->display->display_options['fields']['pid']['field'] = 'pid';
  $handler->display->display_options['fields']['pid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['pid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['pid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['pid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['pid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['pid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['pid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['pid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['pid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['pid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['pid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['pid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['pid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['pid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['pid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['pid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['pid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['pid']['format_plural'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'ledger/accounts/all';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'All Accounts';
  $handler->display->display_options['menu']['weight'] = '-10';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Accounts';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';
  
  /**
   * End ledger_accounts view.
   */
  
  $views[$view->name] = $view;
  
  /**
   * Begin ledger_transactions view.
   */
  
  $view = new view;
  $view->name = 'ledger_transactions';
  $view->description = 'View of ledger transactions.';
  $view->tag = 'default';
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
  /* Field: Ledger Transaction: Description */
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
  /* Field: Ledger Transaction: Value */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'ledger_transaction';
  $handler->display->display_options['fields']['value']['field'] = 'value';
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
  $handler->display->display_options['fields']['value']['format_plural'] = 0;
  /* Field: Ledger Transaction: Credit_aid */
  $handler->display->display_options['fields']['credit_aid']['id'] = 'credit_aid';
  $handler->display->display_options['fields']['credit_aid']['table'] = 'ledger_transaction';
  $handler->display->display_options['fields']['credit_aid']['field'] = 'credit_aid';
  $handler->display->display_options['fields']['credit_aid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['credit_aid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['credit_aid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['credit_aid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['credit_aid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['credit_aid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['credit_aid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['credit_aid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['credit_aid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['credit_aid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['credit_aid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['credit_aid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['credit_aid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['credit_aid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['credit_aid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['credit_aid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['credit_aid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['credit_aid']['format_plural'] = 0;
  /* Field: Ledger Transaction: Debit_aid */
  $handler->display->display_options['fields']['debit_aid']['id'] = 'debit_aid';
  $handler->display->display_options['fields']['debit_aid']['table'] = 'ledger_transaction';
  $handler->display->display_options['fields']['debit_aid']['field'] = 'debit_aid';
  $handler->display->display_options['fields']['debit_aid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['debit_aid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['debit_aid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['debit_aid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['debit_aid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['debit_aid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['debit_aid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['debit_aid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['debit_aid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['debit_aid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['debit_aid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['debit_aid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['debit_aid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['debit_aid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['debit_aid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['debit_aid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['debit_aid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['debit_aid']['format_plural'] = 0;
  /* Field: Ledger Transaction: Timestamp */
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
  $handler->display->display_options['fields']['timestamp']['format_plural'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'ledger/transactions/all';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'All Transactions';
  $handler->display->display_options['menu']['weight'] = '-10';
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Transactions';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';
  
  /**
   * Begin ledger_transactions view.
   */
  
  $views[$view->name] = $view;
  
  return $views;
}
