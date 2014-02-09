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
  $view = new view();
  $view->name = 'ledger_transactions';
  $view->description = 'View of ledger transactions.';
  $view->tag = 'ledger';
  $view->base_table = 'ledger_transaction';
  $view->human_name = 'Ledger Transactions';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'All Transactions';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view all ledger_transaction';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Transactions per page';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '50, 100, 500, 1000';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'timestamp' => 'timestamp',
    'description' => 'description',
    'name' => 'name',
    'name_1' => 'name_1',
    'transaction_ops' => 'transaction_ops',
  );
  $handler->display->display_options['style_options']['default'] = 'timestamp';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'timestamp' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'description' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'transaction_ops' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '(none)';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  /* Relationship: Transaction: Book bid */
  $handler->display->display_options['relationships']['book']['id'] = 'book';
  $handler->display->display_options['relationships']['book']['table'] = 'ledger_transaction';
  $handler->display->display_options['relationships']['book']['field'] = 'book';
  /* Relationship: Book: Owner uid */
  $handler->display->display_options['relationships']['owner']['id'] = 'owner';
  $handler->display->display_options['relationships']['owner']['table'] = 'ledger_book';
  $handler->display->display_options['relationships']['owner']['field'] = 'owner';
  $handler->display->display_options['relationships']['owner']['relationship'] = 'book';
  $handler->display->display_options['relationships']['owner']['label'] = 'Owner';
  /* Field: Bulk operations: Transaction */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'ledger_transaction';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::system_message_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
      'postpone_processing' => 0,
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'action::system_goto_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'postpone_processing' => 0,
    ),
  );
  /* Field: Transaction: Timestamp */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'ledger_transaction';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'custom';
  $handler->display->display_options['fields']['timestamp']['custom_date_format'] = 'm/d/Y g:i a';
  /* Field: Transaction: Description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'ledger_transaction';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['hide_alter_empty'] = FALSE;
  /* Field: Book: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'ledger_book';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'book';
  $handler->display->display_options['fields']['name']['label'] = 'Book';
  $handler->display->display_options['fields']['name']['link_to_book'] = 'view';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'users';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['relationship'] = 'owner';
  $handler->display->display_options['fields']['name_1']['label'] = 'Owner';
  /* Field: Transaction: Operations */
  $handler->display->display_options['fields']['transaction_ops']['id'] = 'transaction_ops';
  $handler->display->display_options['fields']['transaction_ops']['table'] = 'ledger_transaction';
  $handler->display->display_options['fields']['transaction_ops']['field'] = 'transaction_ops';
  $handler->display->display_options['fields']['transaction_ops']['hide_alter_empty'] = FALSE;
  /* Filter criterion: Transaction: Description */
  $handler->display->display_options['filters']['description']['id'] = 'description';
  $handler->display->display_options['filters']['description']['table'] = 'ledger_transaction';
  $handler->display->display_options['filters']['description']['field'] = 'description';
  $handler->display->display_options['filters']['description']['operator'] = 'contains';
  $handler->display->display_options['filters']['description']['group'] = 1;
  $handler->display->display_options['filters']['description']['exposed'] = TRUE;
  $handler->display->display_options['filters']['description']['expose']['operator_id'] = 'description_op';
  $handler->display->display_options['filters']['description']['expose']['label'] = 'Description';
  $handler->display->display_options['filters']['description']['expose']['operator'] = 'description_op';
  $handler->display->display_options['filters']['description']['expose']['identifier'] = 'description';
  $handler->display->display_options['filters']['description']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Transaction: Timestamp */
  $handler->display->display_options['filters']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['filters']['timestamp']['table'] = 'ledger_transaction';
  $handler->display->display_options['filters']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['filters']['timestamp']['operator'] = 'between';
  $handler->display->display_options['filters']['timestamp']['group'] = 1;
  $handler->display->display_options['filters']['timestamp']['exposed'] = TRUE;
  $handler->display->display_options['filters']['timestamp']['expose']['operator_id'] = 'timestamp_op';
  $handler->display->display_options['filters']['timestamp']['expose']['label'] = 'Time between';
  $handler->display->display_options['filters']['timestamp']['expose']['operator'] = 'timestamp_op';
  $handler->display->display_options['filters']['timestamp']['expose']['identifier'] = 'timestamp';
  $handler->display->display_options['filters']['timestamp']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: User: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['relationship'] = 'owner';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['group'] = 1;
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Owner';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
  $handler->display->display_options['filters']['uid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Book: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'ledger_book';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'book';
  $handler->display->display_options['filters']['name']['operator'] = 'contains';
  $handler->display->display_options['filters']['name']['group'] = 1;
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Book';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );

  /* Display: All transactions (page) */
  $handler = $view->new_display('page', 'All transactions (page)', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'admin/ledger/transactions';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Transactions';
  $handler->display->display_options['menu']['weight'] = '20';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Transactions';
  $handler->display->display_options['tab_options']['description'] = 'Manage transactions in the ledger.';
  $handler->display->display_options['tab_options']['weight'] = '30';
  $handler->display->display_options['tab_options']['name'] = 'management';

  /* Display: Transactions by account (page) */
  $handler = $view->new_display('page', 'Transactions by account (page)', 'page_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view own ledger_transaction';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'timestamp' => 'timestamp',
    'description' => 'description',
    'ledger_value' => 'ledger_value',
    'ledger_value_1' => 'ledger_value_1',
    'ledger_balance' => 'ledger_balance',
    'transaction_ops' => 'transaction_ops',
  );
  $handler->display->display_options['style_options']['default'] = 'timestamp';
  $handler->display->display_options['style_options']['info'] = array(
    'timestamp' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'description' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'ledger_value' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'ledger_value_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'ledger_balance' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'transaction_ops' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Transaction: Account entry */
  $handler->display->display_options['relationships']['ledger_account_entry']['id'] = 'ledger_account_entry';
  $handler->display->display_options['relationships']['ledger_account_entry']['table'] = 'ledger_transaction';
  $handler->display->display_options['relationships']['ledger_account_entry']['field'] = 'ledger_account_entry';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Transaction: Timestamp */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'ledger_transaction';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'custom';
  $handler->display->display_options['fields']['timestamp']['custom_date_format'] = 'm/d/Y g:i a';
  /* Field: Transaction: Description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'ledger_transaction';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['hide_alter_empty'] = FALSE;
  /* Field: Field: Value */
  $handler->display->display_options['fields']['ledger_value']['id'] = 'ledger_value';
  $handler->display->display_options['fields']['ledger_value']['table'] = 'field_data_ledger_value';
  $handler->display->display_options['fields']['ledger_value']['field'] = 'ledger_value';
  $handler->display->display_options['fields']['ledger_value']['relationship'] = 'ledger_account_entry';
  $handler->display->display_options['fields']['ledger_value']['label'] = 'Debit';
  $handler->display->display_options['fields']['ledger_value']['type'] = 'fraction_decimal';
  $handler->display->display_options['fields']['ledger_value']['settings'] = array(
    'precision' => '2',
  );
  $handler->display->display_options['fields']['ledger_value']['condition'] = 'increase';
  /* Field: Field: Value */
  $handler->display->display_options['fields']['ledger_value_1']['id'] = 'ledger_value_1';
  $handler->display->display_options['fields']['ledger_value_1']['table'] = 'field_data_ledger_value';
  $handler->display->display_options['fields']['ledger_value_1']['field'] = 'ledger_value';
  $handler->display->display_options['fields']['ledger_value_1']['relationship'] = 'ledger_account_entry';
  $handler->display->display_options['fields']['ledger_value_1']['label'] = 'Credit';
  $handler->display->display_options['fields']['ledger_value_1']['type'] = 'fraction_decimal';
  $handler->display->display_options['fields']['ledger_value_1']['settings'] = array(
    'precision' => '2',
  );
  $handler->display->display_options['fields']['ledger_value_1']['condition'] = 'decrease';
  /* Field: Field: Balance */
  $handler->display->display_options['fields']['ledger_balance']['id'] = 'ledger_balance';
  $handler->display->display_options['fields']['ledger_balance']['table'] = 'field_data_ledger_balance';
  $handler->display->display_options['fields']['ledger_balance']['field'] = 'ledger_balance';
  $handler->display->display_options['fields']['ledger_balance']['relationship'] = 'ledger_account_entry';
  $handler->display->display_options['fields']['ledger_balance']['type'] = 'fraction_decimal';
  $handler->display->display_options['fields']['ledger_balance']['settings'] = array(
    'precision' => '2',
  );
  /* Field: Transaction: Operations */
  $handler->display->display_options['fields']['transaction_ops']['id'] = 'transaction_ops';
  $handler->display->display_options['fields']['transaction_ops']['table'] = 'ledger_transaction';
  $handler->display->display_options['fields']['transaction_ops']['field'] = 'transaction_ops';
  $handler->display->display_options['fields']['transaction_ops']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Account entry: Account aid */
  $handler->display->display_options['arguments']['account']['id'] = 'account';
  $handler->display->display_options['arguments']['account']['table'] = 'ledger_account_entry';
  $handler->display->display_options['arguments']['account']['field'] = 'account';
  $handler->display->display_options['arguments']['account']['relationship'] = 'ledger_account_entry';
  $handler->display->display_options['arguments']['account']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['account']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['account']['title'] = 'Transactions in account: %1';
  $handler->display->display_options['arguments']['account']['breadcrumb_enable'] = TRUE;
  $handler->display->display_options['arguments']['account']['breadcrumb'] = '%1';
  $handler->display->display_options['arguments']['account']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['account']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['account']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['account']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['account']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['account']['validate']['type'] = 'ledger_account';
  $handler->display->display_options['arguments']['account']['validate_options']['access'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Transaction: Description */
  $handler->display->display_options['filters']['description']['id'] = 'description';
  $handler->display->display_options['filters']['description']['table'] = 'ledger_transaction';
  $handler->display->display_options['filters']['description']['field'] = 'description';
  $handler->display->display_options['filters']['description']['operator'] = 'contains';
  $handler->display->display_options['filters']['description']['group'] = 1;
  $handler->display->display_options['filters']['description']['exposed'] = TRUE;
  $handler->display->display_options['filters']['description']['expose']['operator_id'] = 'description_op';
  $handler->display->display_options['filters']['description']['expose']['label'] = 'Description';
  $handler->display->display_options['filters']['description']['expose']['operator'] = 'description_op';
  $handler->display->display_options['filters']['description']['expose']['identifier'] = 'description';
  $handler->display->display_options['filters']['description']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Transaction: Timestamp */
  $handler->display->display_options['filters']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['filters']['timestamp']['table'] = 'ledger_transaction';
  $handler->display->display_options['filters']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['filters']['timestamp']['operator'] = 'between';
  $handler->display->display_options['filters']['timestamp']['group'] = 1;
  $handler->display->display_options['filters']['timestamp']['exposed'] = TRUE;
  $handler->display->display_options['filters']['timestamp']['expose']['operator_id'] = 'timestamp_op';
  $handler->display->display_options['filters']['timestamp']['expose']['label'] = 'Time between';
  $handler->display->display_options['filters']['timestamp']['expose']['operator'] = 'timestamp_op';
  $handler->display->display_options['filters']['timestamp']['expose']['identifier'] = 'timestamp';
  $handler->display->display_options['filters']['timestamp']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['path'] = 'ledger/account/%/transactions';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Transactions';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Account';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';

  /* Display: Transactions by book (page) */
  $handler = $view->new_display('page', 'Transactions by book (page)', 'page_2');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view own ledger_transaction';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'timestamp' => 'timestamp',
    'description' => 'description',
    'name' => 'name',
    'ledger_value' => 'ledger_value',
    'ledger_value_1' => 'ledger_value_1',
    'transaction_ops' => 'transaction_ops',
  );
  $handler->display->display_options['style_options']['default'] = 'timestamp';
  $handler->display->display_options['style_options']['info'] = array(
    'timestamp' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'description' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'ledger_value' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'ledger_value_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'transaction_ops' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Transaction: Account entry */
  $handler->display->display_options['relationships']['ledger_account_entry']['id'] = 'ledger_account_entry';
  $handler->display->display_options['relationships']['ledger_account_entry']['table'] = 'ledger_transaction';
  $handler->display->display_options['relationships']['ledger_account_entry']['field'] = 'ledger_account_entry';
  /* Relationship: Account entry: Account aid */
  $handler->display->display_options['relationships']['account']['id'] = 'account';
  $handler->display->display_options['relationships']['account']['table'] = 'ledger_account_entry';
  $handler->display->display_options['relationships']['account']['field'] = 'account';
  $handler->display->display_options['relationships']['account']['relationship'] = 'ledger_account_entry';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Transaction: Timestamp */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'ledger_transaction';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'custom';
  $handler->display->display_options['fields']['timestamp']['custom_date_format'] = 'm/d/Y g:i a';
  /* Field: Transaction: Description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'ledger_transaction';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['hide_alter_empty'] = FALSE;
  /* Field: Account: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'ledger_account';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'account';
  $handler->display->display_options['fields']['name']['label'] = 'Account';
  $handler->display->display_options['fields']['name']['link_to_account'] = 'view';
  /* Field: Field: Value */
  $handler->display->display_options['fields']['ledger_value']['id'] = 'ledger_value';
  $handler->display->display_options['fields']['ledger_value']['table'] = 'field_data_ledger_value';
  $handler->display->display_options['fields']['ledger_value']['field'] = 'ledger_value';
  $handler->display->display_options['fields']['ledger_value']['relationship'] = 'ledger_account_entry';
  $handler->display->display_options['fields']['ledger_value']['label'] = 'Credit';
  $handler->display->display_options['fields']['ledger_value']['type'] = 'fraction_decimal';
  $handler->display->display_options['fields']['ledger_value']['settings'] = array(
    'precision' => '2',
  );
  $handler->display->display_options['fields']['ledger_value']['condition'] = 'decrease';
  /* Field: Field: Value */
  $handler->display->display_options['fields']['ledger_value_1']['id'] = 'ledger_value_1';
  $handler->display->display_options['fields']['ledger_value_1']['table'] = 'field_data_ledger_value';
  $handler->display->display_options['fields']['ledger_value_1']['field'] = 'ledger_value';
  $handler->display->display_options['fields']['ledger_value_1']['relationship'] = 'ledger_account_entry';
  $handler->display->display_options['fields']['ledger_value_1']['label'] = 'Debit';
  $handler->display->display_options['fields']['ledger_value_1']['type'] = 'fraction_decimal';
  $handler->display->display_options['fields']['ledger_value_1']['settings'] = array(
    'precision' => '2',
  );
  $handler->display->display_options['fields']['ledger_value_1']['condition'] = 'increase';
  /* Field: Transaction: Operations */
  $handler->display->display_options['fields']['transaction_ops']['id'] = 'transaction_ops';
  $handler->display->display_options['fields']['transaction_ops']['table'] = 'ledger_transaction';
  $handler->display->display_options['fields']['transaction_ops']['field'] = 'transaction_ops';
  $handler->display->display_options['fields']['transaction_ops']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Account: Book bid */
  $handler->display->display_options['arguments']['book']['id'] = 'book';
  $handler->display->display_options['arguments']['book']['table'] = 'ledger_account';
  $handler->display->display_options['arguments']['book']['field'] = 'book';
  $handler->display->display_options['arguments']['book']['relationship'] = 'account';
  $handler->display->display_options['arguments']['book']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['book']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['book']['title'] = 'Transactions in book: %1';
  $handler->display->display_options['arguments']['book']['breadcrumb_enable'] = TRUE;
  $handler->display->display_options['arguments']['book']['breadcrumb'] = '%1';
  $handler->display->display_options['arguments']['book']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['book']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['book']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['book']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['book']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['book']['validate']['type'] = 'ledger_book';
  $handler->display->display_options['arguments']['book']['validate_options']['access'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Transaction: Description */
  $handler->display->display_options['filters']['description']['id'] = 'description';
  $handler->display->display_options['filters']['description']['table'] = 'ledger_transaction';
  $handler->display->display_options['filters']['description']['field'] = 'description';
  $handler->display->display_options['filters']['description']['operator'] = 'contains';
  $handler->display->display_options['filters']['description']['group'] = 1;
  $handler->display->display_options['filters']['description']['exposed'] = TRUE;
  $handler->display->display_options['filters']['description']['expose']['operator_id'] = 'description_op';
  $handler->display->display_options['filters']['description']['expose']['label'] = 'Description';
  $handler->display->display_options['filters']['description']['expose']['operator'] = 'description_op';
  $handler->display->display_options['filters']['description']['expose']['identifier'] = 'description';
  $handler->display->display_options['filters']['description']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Transaction: Timestamp */
  $handler->display->display_options['filters']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['filters']['timestamp']['table'] = 'ledger_transaction';
  $handler->display->display_options['filters']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['filters']['timestamp']['operator'] = 'between';
  $handler->display->display_options['filters']['timestamp']['group'] = 1;
  $handler->display->display_options['filters']['timestamp']['exposed'] = TRUE;
  $handler->display->display_options['filters']['timestamp']['expose']['operator_id'] = 'timestamp_op';
  $handler->display->display_options['filters']['timestamp']['expose']['label'] = 'Time between';
  $handler->display->display_options['filters']['timestamp']['expose']['operator'] = 'timestamp_op';
  $handler->display->display_options['filters']['timestamp']['expose']['identifier'] = 'timestamp';
  $handler->display->display_options['filters']['timestamp']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['path'] = 'ledger/book/%/transactions';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Transactions';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  /**
   * End ledger_transactions view.
   */

  $views[$view->name] = $view;

  return $views;
}

