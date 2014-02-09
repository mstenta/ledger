<?php

/**
 * @file
 * Views for the default ledger Budget UI.
 */

/**
 * Implements hook_views_default_views().
 */
function ledger_budget_ui_views_default_views() {
  $views = array();

  /**
   * Begin ledger_budgets view.
   */
  $view = new view();
  $view->name = 'ledger_budgets';
  $view->description = 'View of all Ledger Budgets';
  $view->tag = 'ledger';
  $view->base_table = 'ledger_budget';
  $view->human_name = 'Ledger Budgets';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'All Budgets';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view all ledger_budget';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'name' => 'name',
    'ledger_value' => 'ledger_value',
    'name_1' => 'name_1',
    'effective' => 'effective',
    'expires' => 'expires',
    'repeat_every' => 'repeat_every',
    'repeat_unit' => 'repeat_every',
    'description' => 'description',
    'budget_ops' => 'budget_ops',
    'name_2' => 'name_2',
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
    'ledger_value' => array(
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
    'effective' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'expires' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'repeat_every' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'repeat_unit' => array(
      'sortable' => 0,
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
    'budget_ops' => array(
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
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['content'] = 'No budgets have been created.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Budget: Budget Account ID budget_aid */
  $handler->display->display_options['relationships']['budget_account']['id'] = 'budget_account';
  $handler->display->display_options['relationships']['budget_account']['table'] = 'ledger_budget';
  $handler->display->display_options['relationships']['budget_account']['field'] = 'budget_account';
  $handler->display->display_options['relationships']['budget_account']['label'] = 'Budget Account';
  /* Relationship: Budget: Target Account ID target_aid */
  $handler->display->display_options['relationships']['target_account']['id'] = 'target_account';
  $handler->display->display_options['relationships']['target_account']['table'] = 'ledger_budget';
  $handler->display->display_options['relationships']['target_account']['field'] = 'target_account';
  $handler->display->display_options['relationships']['target_account']['label'] = 'Target Account';
  /* Field: Bulk operations: Budget */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'ledger_budget';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
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
    'action::system_send_email_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Account: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'ledger_account';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'budget_account';
  $handler->display->display_options['fields']['name']['label'] = 'Budget Account';
  /* Field: Field: Value */
  $handler->display->display_options['fields']['ledger_value']['id'] = 'ledger_value';
  $handler->display->display_options['fields']['ledger_value']['table'] = 'field_data_ledger_value';
  $handler->display->display_options['fields']['ledger_value']['field'] = 'ledger_value';
  $handler->display->display_options['fields']['ledger_value']['type'] = 'fraction_decimal';
  $handler->display->display_options['fields']['ledger_value']['settings'] = array(
    'precision' => '2',
  );
  /* Field: Account: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'ledger_account';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['relationship'] = 'target_account';
  $handler->display->display_options['fields']['name_1']['label'] = 'Target Account';
  /* Field: Budget: Effective */
  $handler->display->display_options['fields']['effective']['id'] = 'effective';
  $handler->display->display_options['fields']['effective']['table'] = 'ledger_budget';
  $handler->display->display_options['fields']['effective']['field'] = 'effective';
  $handler->display->display_options['fields']['effective']['date_format'] = 'custom';
  $handler->display->display_options['fields']['effective']['custom_date_format'] = 'm/d/Y g:i a';
  /* Field: Budget: Expires */
  $handler->display->display_options['fields']['expires']['id'] = 'expires';
  $handler->display->display_options['fields']['expires']['table'] = 'ledger_budget';
  $handler->display->display_options['fields']['expires']['field'] = 'expires';
  $handler->display->display_options['fields']['expires']['date_format'] = 'custom';
  $handler->display->display_options['fields']['expires']['custom_date_format'] = 'm/d/Y g:i a';
  /* Field: Budget: Repeat Every */
  $handler->display->display_options['fields']['repeat_every']['id'] = 'repeat_every';
  $handler->display->display_options['fields']['repeat_every']['table'] = 'ledger_budget';
  $handler->display->display_options['fields']['repeat_every']['field'] = 'repeat_every';
  $handler->display->display_options['fields']['repeat_every']['suffix'] = ' ';
  /* Field: Budget: Repeat Unit */
  $handler->display->display_options['fields']['repeat_unit']['id'] = 'repeat_unit';
  $handler->display->display_options['fields']['repeat_unit']['table'] = 'ledger_budget';
  $handler->display->display_options['fields']['repeat_unit']['field'] = 'repeat_unit';
  /* Field: Budget: Description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'ledger_budget';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['link_to_budget'] = 'view';
  /* Field: Budget: Operations */
  $handler->display->display_options['fields']['budget_ops']['id'] = 'budget_ops';
  $handler->display->display_options['fields']['budget_ops']['table'] = 'ledger_budget';
  $handler->display->display_options['fields']['budget_ops']['field'] = 'budget_ops';
  /* Sort criterion: Account: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'ledger_account';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  $handler->display->display_options['sorts']['name']['relationship'] = 'budget_account';
  /* Filter criterion: Budget: Description */
  $handler->display->display_options['filters']['description']['id'] = 'description';
  $handler->display->display_options['filters']['description']['table'] = 'ledger_budget';
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
  /* Filter criterion: Account: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'ledger_account';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'budget_account';
  $handler->display->display_options['filters']['name']['operator'] = 'contains';
  $handler->display->display_options['filters']['name']['group'] = 1;
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Budget account';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Account: Name */
  $handler->display->display_options['filters']['name_1']['id'] = 'name_1';
  $handler->display->display_options['filters']['name_1']['table'] = 'ledger_account';
  $handler->display->display_options['filters']['name_1']['field'] = 'name';
  $handler->display->display_options['filters']['name_1']['relationship'] = 'target_account';
  $handler->display->display_options['filters']['name_1']['operator'] = 'contains';
  $handler->display->display_options['filters']['name_1']['group'] = 1;
  $handler->display->display_options['filters']['name_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name_1']['expose']['operator_id'] = 'name_1_op';
  $handler->display->display_options['filters']['name_1']['expose']['label'] = 'Target account';
  $handler->display->display_options['filters']['name_1']['expose']['operator'] = 'name_1_op';
  $handler->display->display_options['filters']['name_1']['expose']['identifier'] = 'name_1';
  $handler->display->display_options['filters']['name_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );

  /* Display: All budgets (page) */
  $handler = $view->new_display('page', 'All budgets (page)', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'admin/ledger/budgets';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Budgets';
  $handler->display->display_options['menu']['weight'] = '50';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Budgets';
  $handler->display->display_options['tab_options']['description'] = 'Manage transactions in the ledger.';
  $handler->display->display_options['tab_options']['weight'] = '100';
  $handler->display->display_options['tab_options']['name'] = 'management';

  /* Display: Budgets by book (page) */
  $handler = $view->new_display('page', 'Budgets by book (page)', 'page_1');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view own ledger_budget';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'ledger_value' => 'ledger_value',
    'name_1' => 'name_1',
    'effective' => 'effective',
    'expires' => 'expires',
    'repeat_every' => 'repeat_every',
    'repeat_unit' => 'repeat_every',
    'description' => 'description',
    'budget_ops' => 'budget_ops',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
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
    'name_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'effective' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'expires' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'repeat_every' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'repeat_unit' => array(
      'sortable' => 0,
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
    'budget_ops' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Budget: Budget Account ID budget_aid */
  $handler->display->display_options['relationships']['budget_account']['id'] = 'budget_account';
  $handler->display->display_options['relationships']['budget_account']['table'] = 'ledger_budget';
  $handler->display->display_options['relationships']['budget_account']['field'] = 'budget_account';
  $handler->display->display_options['relationships']['budget_account']['label'] = 'Budget Account';
  /* Relationship: Budget: Target Account ID target_aid */
  $handler->display->display_options['relationships']['target_account']['id'] = 'target_account';
  $handler->display->display_options['relationships']['target_account']['table'] = 'ledger_budget';
  $handler->display->display_options['relationships']['target_account']['field'] = 'target_account';
  $handler->display->display_options['relationships']['target_account']['label'] = 'Target Account';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Account: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'ledger_account';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'budget_account';
  $handler->display->display_options['fields']['name']['label'] = 'Budget Account';
  /* Field: Field: Value */
  $handler->display->display_options['fields']['ledger_value']['id'] = 'ledger_value';
  $handler->display->display_options['fields']['ledger_value']['table'] = 'field_data_ledger_value';
  $handler->display->display_options['fields']['ledger_value']['field'] = 'ledger_value';
  $handler->display->display_options['fields']['ledger_value']['type'] = 'fraction_decimal';
  $handler->display->display_options['fields']['ledger_value']['settings'] = array(
    'precision' => '2',
  );
  /* Field: Account: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'ledger_account';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['relationship'] = 'target_account';
  $handler->display->display_options['fields']['name_1']['label'] = 'Target Account';
  /* Field: Budget: Effective */
  $handler->display->display_options['fields']['effective']['id'] = 'effective';
  $handler->display->display_options['fields']['effective']['table'] = 'ledger_budget';
  $handler->display->display_options['fields']['effective']['field'] = 'effective';
  $handler->display->display_options['fields']['effective']['date_format'] = 'custom';
  $handler->display->display_options['fields']['effective']['custom_date_format'] = 'm/d/Y g:i a';
  /* Field: Budget: Expires */
  $handler->display->display_options['fields']['expires']['id'] = 'expires';
  $handler->display->display_options['fields']['expires']['table'] = 'ledger_budget';
  $handler->display->display_options['fields']['expires']['field'] = 'expires';
  $handler->display->display_options['fields']['expires']['date_format'] = 'custom';
  $handler->display->display_options['fields']['expires']['custom_date_format'] = 'm/d/Y g:i a';
  /* Field: Budget: Repeat Every */
  $handler->display->display_options['fields']['repeat_every']['id'] = 'repeat_every';
  $handler->display->display_options['fields']['repeat_every']['table'] = 'ledger_budget';
  $handler->display->display_options['fields']['repeat_every']['field'] = 'repeat_every';
  $handler->display->display_options['fields']['repeat_every']['suffix'] = ' ';
  /* Field: Budget: Repeat Unit */
  $handler->display->display_options['fields']['repeat_unit']['id'] = 'repeat_unit';
  $handler->display->display_options['fields']['repeat_unit']['table'] = 'ledger_budget';
  $handler->display->display_options['fields']['repeat_unit']['field'] = 'repeat_unit';
  /* Field: Budget: Description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'ledger_budget';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['link_to_budget'] = 'view';
  /* Field: Budget: Operations */
  $handler->display->display_options['fields']['budget_ops']['id'] = 'budget_ops';
  $handler->display->display_options['fields']['budget_ops']['table'] = 'ledger_budget';
  $handler->display->display_options['fields']['budget_ops']['field'] = 'budget_ops';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Account: Book bid */
  $handler->display->display_options['arguments']['book_1']['id'] = 'book_1';
  $handler->display->display_options['arguments']['book_1']['table'] = 'ledger_account';
  $handler->display->display_options['arguments']['book_1']['field'] = 'book';
  $handler->display->display_options['arguments']['book_1']['relationship'] = 'budget_account';
  $handler->display->display_options['arguments']['book_1']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['book_1']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['book_1']['title'] = 'Budgets in book: %1';
  $handler->display->display_options['arguments']['book_1']['breadcrumb_enable'] = TRUE;
  $handler->display->display_options['arguments']['book_1']['breadcrumb'] = '%1';
  $handler->display->display_options['arguments']['book_1']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['book_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['book_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['book_1']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['book_1']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['book_1']['validate']['type'] = 'ledger_book';
  $handler->display->display_options['arguments']['book_1']['validate_options']['access'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Budget: Description */
  $handler->display->display_options['filters']['description']['id'] = 'description';
  $handler->display->display_options['filters']['description']['table'] = 'ledger_budget';
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
  /* Filter criterion: Account: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'ledger_account';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'budget_account';
  $handler->display->display_options['filters']['name']['operator'] = 'contains';
  $handler->display->display_options['filters']['name']['group'] = 1;
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Budget account';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Account: Name */
  $handler->display->display_options['filters']['name_1']['id'] = 'name_1';
  $handler->display->display_options['filters']['name_1']['table'] = 'ledger_account';
  $handler->display->display_options['filters']['name_1']['field'] = 'name';
  $handler->display->display_options['filters']['name_1']['relationship'] = 'target_account';
  $handler->display->display_options['filters']['name_1']['operator'] = 'contains';
  $handler->display->display_options['filters']['name_1']['group'] = 1;
  $handler->display->display_options['filters']['name_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name_1']['expose']['operator_id'] = 'name_1_op';
  $handler->display->display_options['filters']['name_1']['expose']['label'] = 'Target account';
  $handler->display->display_options['filters']['name_1']['expose']['operator'] = 'name_1_op';
  $handler->display->display_options['filters']['name_1']['expose']['identifier'] = 'name_1';
  $handler->display->display_options['filters']['name_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['path'] = 'ledger/book/%/budgets';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Budgets';
  $handler->display->display_options['menu']['weight'] = '50';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  /**
   * End ledger_budgets view.
   */

  $views[$view->name] = $view;

  return $views;
}

