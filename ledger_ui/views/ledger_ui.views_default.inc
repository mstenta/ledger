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
  $handler->display->display_options['style_options']['grouping'] = 'type';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'description' => 'description',
    'type' => 'type',
    'name_1' => 'name_1',
    'view_account' => 'view_account',
    'edit_account' => 'edit_account',
    'delete_account' => 'delete_account',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'description' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'name_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'view_account' => array(
      'align' => '',
      'separator' => '',
    ),
    'edit_account' => array(
      'align' => '',
      'separator' => '',
    ),
    'delete_account' => array(
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
  /* Relationship: Ledger Account: Parent Account pid */
  $handler->display->display_options['relationships']['parent']['id'] = 'parent';
  $handler->display->display_options['relationships']['parent']['table'] = 'ledger_account';
  $handler->display->display_options['relationships']['parent']['field'] = 'parent';
  $handler->display->display_options['relationships']['parent']['label'] = 'Parent Account';
  $handler->display->display_options['relationships']['parent']['required'] = 0;
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
  $handler->display->display_options['fields']['name']['link_to_account'] = 'view';
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
  /* Field: Ledger Account: Account type */
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
  /* Field: Ledger Account: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'ledger_account';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['relationship'] = 'parent';
  $handler->display->display_options['fields']['name_1']['label'] = 'Parent Account';
  $handler->display->display_options['fields']['name_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['name_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name_1']['hide_alter_empty'] = 0;
  /* Field: Ledger Account: Link */
  $handler->display->display_options['fields']['view_account']['id'] = 'view_account';
  $handler->display->display_options['fields']['view_account']['table'] = 'ledger_account';
  $handler->display->display_options['fields']['view_account']['field'] = 'view_account';
  $handler->display->display_options['fields']['view_account']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['view_account']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['view_account']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['view_account']['alter']['external'] = 0;
  $handler->display->display_options['fields']['view_account']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['view_account']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['view_account']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['view_account']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['view_account']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['view_account']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['view_account']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['view_account']['alter']['html'] = 0;
  $handler->display->display_options['fields']['view_account']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['view_account']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['view_account']['hide_empty'] = 0;
  $handler->display->display_options['fields']['view_account']['empty_zero'] = 0;
  $handler->display->display_options['fields']['view_account']['hide_alter_empty'] = 0;
  /* Field: Ledger Account: Edit link */
  $handler->display->display_options['fields']['edit_account']['id'] = 'edit_account';
  $handler->display->display_options['fields']['edit_account']['table'] = 'ledger_account';
  $handler->display->display_options['fields']['edit_account']['field'] = 'edit_account';
  $handler->display->display_options['fields']['edit_account']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['edit_account']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['edit_account']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['edit_account']['alter']['external'] = 0;
  $handler->display->display_options['fields']['edit_account']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['edit_account']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['edit_account']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['edit_account']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['edit_account']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['edit_account']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['edit_account']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['edit_account']['alter']['html'] = 0;
  $handler->display->display_options['fields']['edit_account']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['edit_account']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['edit_account']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit_account']['empty_zero'] = 0;
  $handler->display->display_options['fields']['edit_account']['hide_alter_empty'] = 0;
  /* Field: Ledger Account: Delete link */
  $handler->display->display_options['fields']['delete_account']['id'] = 'delete_account';
  $handler->display->display_options['fields']['delete_account']['table'] = 'ledger_account';
  $handler->display->display_options['fields']['delete_account']['field'] = 'delete_account';
  $handler->display->display_options['fields']['delete_account']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['delete_account']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['delete_account']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['delete_account']['alter']['external'] = 0;
  $handler->display->display_options['fields']['delete_account']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['delete_account']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['delete_account']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['delete_account']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['delete_account']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['delete_account']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['delete_account']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['delete_account']['alter']['html'] = 0;
  $handler->display->display_options['fields']['delete_account']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['delete_account']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['delete_account']['hide_empty'] = 0;
  $handler->display->display_options['fields']['delete_account']['empty_zero'] = 0;
  $handler->display->display_options['fields']['delete_account']['hide_alter_empty'] = 0;
  
  /* Display: All accounts (page) */
  $handler = $view->new_display('page', 'All accounts (page)', 'page');
  $handler->display->display_options['display_description'] = 'View displaying all accounts grouped by type.';
  $handler->display->display_options['path'] = 'admin/ledger/accounts/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'List';
  $handler->display->display_options['menu']['weight'] = '-10';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Accounts';
  $handler->display->display_options['tab_options']['description'] = 'Manage accounts in the ledger.';
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
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'custom';
  $handler->display->display_options['fields']['timestamp']['custom_date_format'] = 'm/d/Y g:i a';
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
  $handler->display->display_options['fields']['description']['link_to_transaction'] = 'view';
  /* Field: Ledger Transaction: Ledger Entries */
  $handler->display->display_options['fields']['lender_transaction_entry']['id'] = 'lender_transaction_entry';
  $handler->display->display_options['fields']['lender_transaction_entry']['table'] = 'field_data_lender_transaction_entry';
  $handler->display->display_options['fields']['lender_transaction_entry']['field'] = 'lender_transaction_entry';
  $handler->display->display_options['fields']['lender_transaction_entry']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['lender_transaction_entry']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['lender_transaction_entry']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['lender_transaction_entry']['alter']['external'] = 0;
  $handler->display->display_options['fields']['lender_transaction_entry']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['lender_transaction_entry']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['lender_transaction_entry']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['lender_transaction_entry']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['lender_transaction_entry']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['lender_transaction_entry']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['lender_transaction_entry']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['lender_transaction_entry']['alter']['html'] = 0;
  $handler->display->display_options['fields']['lender_transaction_entry']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['lender_transaction_entry']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['lender_transaction_entry']['hide_empty'] = 0;
  $handler->display->display_options['fields']['lender_transaction_entry']['empty_zero'] = 0;
  $handler->display->display_options['fields']['lender_transaction_entry']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['lender_transaction_entry']['group_rows'] = 0;
  $handler->display->display_options['fields']['lender_transaction_entry']['delta_offset'] = '0';
  $handler->display->display_options['fields']['lender_transaction_entry']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['lender_transaction_entry']['field_api_classes'] = 0;
  /* Field: Ledger Transaction: Link */
  $handler->display->display_options['fields']['view_transaction']['id'] = 'view_transaction';
  $handler->display->display_options['fields']['view_transaction']['table'] = 'ledger_transaction';
  $handler->display->display_options['fields']['view_transaction']['field'] = 'view_transaction';
  $handler->display->display_options['fields']['view_transaction']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['view_transaction']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['view_transaction']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['view_transaction']['alter']['external'] = 0;
  $handler->display->display_options['fields']['view_transaction']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['view_transaction']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['view_transaction']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['view_transaction']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['view_transaction']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['view_transaction']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['view_transaction']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['view_transaction']['alter']['html'] = 0;
  $handler->display->display_options['fields']['view_transaction']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['view_transaction']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['view_transaction']['hide_empty'] = 0;
  $handler->display->display_options['fields']['view_transaction']['empty_zero'] = 0;
  $handler->display->display_options['fields']['view_transaction']['hide_alter_empty'] = 0;
  /* Field: Ledger Transaction: Edit link */
  $handler->display->display_options['fields']['edit_transaction']['id'] = 'edit_transaction';
  $handler->display->display_options['fields']['edit_transaction']['table'] = 'ledger_transaction';
  $handler->display->display_options['fields']['edit_transaction']['field'] = 'edit_transaction';
  $handler->display->display_options['fields']['edit_transaction']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['edit_transaction']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['edit_transaction']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['edit_transaction']['alter']['external'] = 0;
  $handler->display->display_options['fields']['edit_transaction']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['edit_transaction']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['edit_transaction']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['edit_transaction']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['edit_transaction']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['edit_transaction']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['edit_transaction']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['edit_transaction']['alter']['html'] = 0;
  $handler->display->display_options['fields']['edit_transaction']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['edit_transaction']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['edit_transaction']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit_transaction']['empty_zero'] = 0;
  $handler->display->display_options['fields']['edit_transaction']['hide_alter_empty'] = 0;
  /* Field: Ledger Transaction: Delete link */
  $handler->display->display_options['fields']['delete_transaction']['id'] = 'delete_transaction';
  $handler->display->display_options['fields']['delete_transaction']['table'] = 'ledger_transaction';
  $handler->display->display_options['fields']['delete_transaction']['field'] = 'delete_transaction';
  $handler->display->display_options['fields']['delete_transaction']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['delete_transaction']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['delete_transaction']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['delete_transaction']['alter']['external'] = 0;
  $handler->display->display_options['fields']['delete_transaction']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['delete_transaction']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['delete_transaction']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['delete_transaction']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['delete_transaction']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['delete_transaction']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['delete_transaction']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['delete_transaction']['alter']['html'] = 0;
  $handler->display->display_options['fields']['delete_transaction']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['delete_transaction']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['delete_transaction']['hide_empty'] = 0;
  $handler->display->display_options['fields']['delete_transaction']['empty_zero'] = 0;
  $handler->display->display_options['fields']['delete_transaction']['hide_alter_empty'] = 0;
  /* Contextual filter: Ledger Transaction: Ledger Entries (lender_transaction_entry:aid) */
  $handler->display->display_options['arguments']['lender_transaction_entry_aid']['id'] = 'lender_transaction_entry_aid';
  $handler->display->display_options['arguments']['lender_transaction_entry_aid']['table'] = 'field_data_lender_transaction_entry';
  $handler->display->display_options['arguments']['lender_transaction_entry_aid']['field'] = 'lender_transaction_entry_aid';
  $handler->display->display_options['arguments']['lender_transaction_entry_aid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['lender_transaction_entry_aid']['title_enable'] = 1;
  $handler->display->display_options['arguments']['lender_transaction_entry_aid']['title'] = 'Ledger Transactions in Account %1';
  $handler->display->display_options['arguments']['lender_transaction_entry_aid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['lender_transaction_entry_aid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['lender_transaction_entry_aid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['lender_transaction_entry_aid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['lender_transaction_entry_aid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['lender_transaction_entry_aid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['lender_transaction_entry_aid']['not'] = 0;
  
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
