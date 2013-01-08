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
  $handler->display->display_options['title'] = 'Ledger Transactions';
  $handler->display->display_options['use_more_always'] = FALSE;
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
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = TRUE;
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
  $handler->display->display_options['style_options']['order'] = 'desc';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['content'] = 'No transactions have been created yet.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: Bulk operations: Transaction */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'ledger_transaction';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_result'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_message_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
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
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
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
  $handler->display->display_options['fields']['description']['link_to_transaction'] = 'view';
  /* Field: Transaction: Operations */
  $handler->display->display_options['fields']['transaction_ops']['id'] = 'transaction_ops';
  $handler->display->display_options['fields']['transaction_ops']['table'] = 'ledger_transaction';
  $handler->display->display_options['fields']['transaction_ops']['field'] = 'transaction_ops';
  $handler->display->display_options['fields']['transaction_ops']['hide_alter_empty'] = FALSE;

  /* Display: All transactions (page) */
  $handler = $view->new_display('page', 'All transactions (page)', 'page');
  $handler->display->display_options['display_description'] = 'Page displaying all transactions.';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
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
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'timestamp' => 'timestamp',
    'description' => 'description',
    'value' => 'value',
    'value_1' => 'value_1',
    'balance' => 'balance',
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
    'value' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'value_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'balance' => array(
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
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['content'] = 'No transactions in this account.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Transaction: Account entry */
  $handler->display->display_options['relationships']['ledger_account_entry']['id'] = 'ledger_account_entry';
  $handler->display->display_options['relationships']['ledger_account_entry']['table'] = 'ledger_transaction';
  $handler->display->display_options['relationships']['ledger_account_entry']['field'] = 'ledger_account_entry';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Transaction */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'ledger_transaction';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_result'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_message_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
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
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
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
  $handler->display->display_options['fields']['description']['link_to_transaction'] = 'view';
  /* Field: Account entry: Value */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'ledger_account_entry';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['relationship'] = 'ledger_account_entry';
  $handler->display->display_options['fields']['value']['label'] = 'Debit';
  $handler->display->display_options['fields']['value']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['value']['precision'] = '2';
  $handler->display->display_options['fields']['value']['format'] = 'increase';
  /* Field: Account entry: Value */
  $handler->display->display_options['fields']['value_1']['id'] = 'value_1';
  $handler->display->display_options['fields']['value_1']['table'] = 'ledger_account_entry';
  $handler->display->display_options['fields']['value_1']['field'] = 'value';
  $handler->display->display_options['fields']['value_1']['relationship'] = 'ledger_account_entry';
  $handler->display->display_options['fields']['value_1']['label'] = 'Credit';
  $handler->display->display_options['fields']['value_1']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['value_1']['precision'] = '2';
  $handler->display->display_options['fields']['value_1']['format'] = 'decrease';
  /* Field: Account entry: Balance */
  $handler->display->display_options['fields']['balance']['id'] = 'balance';
  $handler->display->display_options['fields']['balance']['table'] = 'ledger_account_entry';
  $handler->display->display_options['fields']['balance']['field'] = 'balance';
  $handler->display->display_options['fields']['balance']['relationship'] = 'ledger_account_entry';
  $handler->display->display_options['fields']['balance']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['balance']['precision'] = '2';
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
  $handler->display->display_options['arguments']['account']['title'] = 'Transactions in %1';
  $handler->display->display_options['arguments']['account']['breadcrumb_enable'] = TRUE;
  $handler->display->display_options['arguments']['account']['breadcrumb'] = '%1';
  $handler->display->display_options['arguments']['account']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['account']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['account']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['account']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['account']['specify_validation'] = TRUE;
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