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
  $handler->display->display_options['title'] = 'Ledger Budgets';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer ledger';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'value' => 'value',
    'name_1' => 'name_1',
    'effective' => 'effective',
    'expires' => 'expires',
    'repeat_every' => 'repeat_every',
    'repeat_unit' => 'repeat_every',
    'description' => 'description',
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
    'value' => array(
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
  /* Field: Account: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'ledger_account';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'budget_account';
  $handler->display->display_options['fields']['name']['label'] = 'Budget Account';
  /* Field: Budget: Value */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'ledger_budget';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['value']['precision'] = '2';
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

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'admin/ledger/budgets/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'List';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Budgets';
  $handler->display->display_options['tab_options']['description'] = 'Manage transactions in the ledger.';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';
  /**
   * End ledger_budgets view.
   */

  $views[$view->name] = $view;

  return $views;
}