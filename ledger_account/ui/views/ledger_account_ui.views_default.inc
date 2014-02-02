<?php

/**
 * @file
 * Views for the default Ledger Account UI.
 */

/**
 * Implements hook_views_default_views().
 */
function ledger_account_ui_views_default_views() {
  $views = array();

  /**
   * Begin ledger_accounts view.
   */
  $view = new view();
  $view->name = 'ledger_accounts';
  $view->description = 'View of all Ledger Accounts';
  $view->tag = 'ledger';
  $view->base_table = 'ledger_account';
  $view->human_name = 'Ledger Accounts';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Accounts';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view all ledger_account';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Accounts per page';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '10, 50, 100, 200';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'name' => 'name',
    'description' => 'description',
    'type' => 'type',
    'name_1' => 'name_1',
    'name_3' => 'name_3',
    'name_2' => 'name_2',
    'ledger_balance' => 'ledger_balance',
    'account_ops' => 'account_ops',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
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
    'description' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name_3' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name_2' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'ledger_balance' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'account_ops' => array(
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
  /* Relationship: Account: Book bid */
  $handler->display->display_options['relationships']['book']['id'] = 'book';
  $handler->display->display_options['relationships']['book']['table'] = 'ledger_account';
  $handler->display->display_options['relationships']['book']['field'] = 'book';
  /* Relationship: Book: Owner uid */
  $handler->display->display_options['relationships']['owner']['id'] = 'owner';
  $handler->display->display_options['relationships']['owner']['table'] = 'ledger_book';
  $handler->display->display_options['relationships']['owner']['field'] = 'owner';
  $handler->display->display_options['relationships']['owner']['relationship'] = 'book';
  $handler->display->display_options['relationships']['owner']['label'] = 'Owner';
  /* Relationship: Account: Parent Account pid */
  $handler->display->display_options['relationships']['parent']['id'] = 'parent';
  $handler->display->display_options['relationships']['parent']['table'] = 'ledger_account';
  $handler->display->display_options['relationships']['parent']['field'] = 'parent';
  $handler->display->display_options['relationships']['parent']['label'] = 'Parent Account';
  /* Field: Bulk operations: Account */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'ledger_account';
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
  /* Field: Account: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'ledger_account';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_account'] = 'view';
  /* Field: Account: Description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'ledger_account';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['hide_alter_empty'] = FALSE;
  /* Field: Account: Account type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'ledger_account';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['hide_alter_empty'] = FALSE;
  /* Field: Account: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'ledger_account';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['relationship'] = 'parent';
  $handler->display->display_options['fields']['name_1']['label'] = 'Parent Account';
  $handler->display->display_options['fields']['name_1']['empty'] = '(none)';
  $handler->display->display_options['fields']['name_1']['hide_alter_empty'] = FALSE;
  /* Field: Field: Balance */
  $handler->display->display_options['fields']['ledger_balance']['id'] = 'ledger_balance';
  $handler->display->display_options['fields']['ledger_balance']['table'] = 'field_data_ledger_balance';
  $handler->display->display_options['fields']['ledger_balance']['field'] = 'ledger_balance';
  $handler->display->display_options['fields']['ledger_balance']['type'] = 'fraction_decimal';
  $handler->display->display_options['fields']['ledger_balance']['settings'] = array(
    'precision' => '2',
  );
  /* Field: Book: Name */
  $handler->display->display_options['fields']['name_3']['id'] = 'name_3';
  $handler->display->display_options['fields']['name_3']['table'] = 'ledger_book';
  $handler->display->display_options['fields']['name_3']['field'] = 'name';
  $handler->display->display_options['fields']['name_3']['relationship'] = 'book';
  $handler->display->display_options['fields']['name_3']['label'] = 'Book';
  $handler->display->display_options['fields']['name_3']['link_to_book'] = 'view';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name_2']['id'] = 'name_2';
  $handler->display->display_options['fields']['name_2']['table'] = 'users';
  $handler->display->display_options['fields']['name_2']['field'] = 'name';
  $handler->display->display_options['fields']['name_2']['relationship'] = 'owner';
  $handler->display->display_options['fields']['name_2']['label'] = 'Owner';
  /* Field: Account: Operations */
  $handler->display->display_options['fields']['account_ops']['id'] = 'account_ops';
  $handler->display->display_options['fields']['account_ops']['table'] = 'ledger_account';
  $handler->display->display_options['fields']['account_ops']['field'] = 'account_ops';
  $handler->display->display_options['fields']['account_ops']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['account_ops']['text'] = 'Ops';
  /* Sort criterion: Account: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'ledger_account';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  /* Filter criterion: Account: Account type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'ledger_account';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Account type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  /* Filter criterion: Account: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'ledger_account';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['operator'] = 'contains';
  $handler->display->display_options['filters']['name']['group'] = 1;
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Account name';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['name_1']['id'] = 'name_1';
  $handler->display->display_options['filters']['name_1']['table'] = 'ledger_book';
  $handler->display->display_options['filters']['name_1']['field'] = 'name';
  $handler->display->display_options['filters']['name_1']['relationship'] = 'book';
  $handler->display->display_options['filters']['name_1']['operator'] = 'contains';
  $handler->display->display_options['filters']['name_1']['group'] = 1;
  $handler->display->display_options['filters']['name_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name_1']['expose']['operator_id'] = 'name_1_op';
  $handler->display->display_options['filters']['name_1']['expose']['label'] = 'Book';
  $handler->display->display_options['filters']['name_1']['expose']['operator'] = 'name_1_op';
  $handler->display->display_options['filters']['name_1']['expose']['identifier'] = 'name_1';
  $handler->display->display_options['filters']['name_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );

  /* Display: All accounts (page) */
  $handler = $view->new_display('page', 'All accounts (page)', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'ledger/accounts';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Accounts';
  $handler->display->display_options['menu']['weight'] = '10';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Accounts';
  $handler->display->display_options['tab_options']['description'] = 'Manage accounts in the ledger.';
  $handler->display->display_options['tab_options']['weight'] = '10';
  $handler->display->display_options['tab_options']['name'] = 'management';

  /* Display: Accounts by book (page) */
  $handler = $view->new_display('page', 'Accounts by book (page)', 'page_1');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view own ledger_account';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'tree';
  $handler->display->display_options['style_options']['main_field'] = 'aid';
  $handler->display->display_options['style_options']['parent_field'] = 'parent';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'name' => 'name',
    'ledger_balance' => 'ledger_balance',
    'account_ops' => 'account_ops',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Account: Account ID */
  $handler->display->display_options['fields']['aid']['id'] = 'aid';
  $handler->display->display_options['fields']['aid']['table'] = 'ledger_account';
  $handler->display->display_options['fields']['aid']['field'] = 'aid';
  $handler->display->display_options['fields']['aid']['exclude'] = TRUE;
  /* Field: Account: Parent Account pid */
  $handler->display->display_options['fields']['parent']['id'] = 'parent';
  $handler->display->display_options['fields']['parent']['table'] = 'ledger_account';
  $handler->display->display_options['fields']['parent']['field'] = 'parent';
  $handler->display->display_options['fields']['parent']['exclude'] = TRUE;
  /* Field: Account: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'ledger_account';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_account'] = 'view';
  /* Field: Field: Balance */
  $handler->display->display_options['fields']['ledger_balance']['id'] = 'ledger_balance';
  $handler->display->display_options['fields']['ledger_balance']['table'] = 'field_data_ledger_balance';
  $handler->display->display_options['fields']['ledger_balance']['field'] = 'ledger_balance';
  $handler->display->display_options['fields']['ledger_balance']['label'] = '';
  $handler->display->display_options['fields']['ledger_balance']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['ledger_balance']['type'] = 'fraction_decimal';
  $handler->display->display_options['fields']['ledger_balance']['settings'] = array(
    'precision' => '2',
  );
  /* Field: Account: Operations */
  $handler->display->display_options['fields']['account_ops']['id'] = 'account_ops';
  $handler->display->display_options['fields']['account_ops']['table'] = 'ledger_account';
  $handler->display->display_options['fields']['account_ops']['field'] = 'account_ops';
  $handler->display->display_options['fields']['account_ops']['label'] = '';
  $handler->display->display_options['fields']['account_ops']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['account_ops']['destination'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Account: Book bid */
  $handler->display->display_options['arguments']['book']['id'] = 'book';
  $handler->display->display_options['arguments']['book']['table'] = 'ledger_account';
  $handler->display->display_options['arguments']['book']['field'] = 'book';
  $handler->display->display_options['arguments']['book']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['book']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['book']['title'] = 'Accounts in book: %1';
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
  /* Filter criterion: Account: Account type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'ledger_account';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Account type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  /* Filter criterion: Account: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'ledger_account';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['operator'] = 'contains';
  $handler->display->display_options['filters']['name']['group'] = 1;
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Account name';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['path'] = 'ledger/book/%/accounts';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Accounts';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Accounts';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';
  /**
   * End ledger_accounts view.
   */

  $views[$view->name] = $view;

  return $views;
}

