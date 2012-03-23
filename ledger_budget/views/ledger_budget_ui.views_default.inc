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
  $view = new view;
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
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Relationship: Budget: Budget Account ID budget_aid */
  $handler->display->display_options['relationships']['budget_account']['id'] = 'budget_account';
  $handler->display->display_options['relationships']['budget_account']['table'] = 'ledger_budget';
  $handler->display->display_options['relationships']['budget_account']['field'] = 'budget_account';
  $handler->display->display_options['relationships']['budget_account']['label'] = 'Budget Account';
  $handler->display->display_options['relationships']['budget_account']['required'] = 0;
  /* Relationship: Budget: Target Account ID target_aid */
  $handler->display->display_options['relationships']['target_account']['id'] = 'target_account';
  $handler->display->display_options['relationships']['target_account']['table'] = 'ledger_budget';
  $handler->display->display_options['relationships']['target_account']['field'] = 'target_account';
  $handler->display->display_options['relationships']['target_account']['label'] = 'Target Account';
  $handler->display->display_options['relationships']['target_account']['required'] = 0;
  /* Field: Account: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'ledger_account';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'budget_account';
  $handler->display->display_options['fields']['name']['label'] = 'Budget Account';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 1;
  /* Field: Budget: Value */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'ledger_budget';
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
  $handler->display->display_options['fields']['value']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['value']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['value']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['value']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['value']['set_precision'] = 1;
  $handler->display->display_options['fields']['value']['precision'] = '2';
  $handler->display->display_options['fields']['value']['format_plural'] = 0;
  /* Field: Account: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'ledger_account';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['relationship'] = 'target_account';
  $handler->display->display_options['fields']['name_1']['label'] = 'Target Account';
  $handler->display->display_options['fields']['name_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name_1']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['name_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name_1']['hide_alter_empty'] = 1;
  /* Field: Budget: Effective */
  $handler->display->display_options['fields']['effective']['id'] = 'effective';
  $handler->display->display_options['fields']['effective']['table'] = 'ledger_budget';
  $handler->display->display_options['fields']['effective']['field'] = 'effective';
  $handler->display->display_options['fields']['effective']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['effective']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['effective']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['effective']['alter']['external'] = 0;
  $handler->display->display_options['fields']['effective']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['effective']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['effective']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['effective']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['effective']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['effective']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['effective']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['effective']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['effective']['alter']['html'] = 0;
  $handler->display->display_options['fields']['effective']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['effective']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['effective']['hide_empty'] = 0;
  $handler->display->display_options['fields']['effective']['empty_zero'] = 0;
  $handler->display->display_options['fields']['effective']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['effective']['date_format'] = 'custom';
  $handler->display->display_options['fields']['effective']['custom_date_format'] = 'm/d/Y g:i a';
  /* Field: Budget: Expires */
  $handler->display->display_options['fields']['expires']['id'] = 'expires';
  $handler->display->display_options['fields']['expires']['table'] = 'ledger_budget';
  $handler->display->display_options['fields']['expires']['field'] = 'expires';
  $handler->display->display_options['fields']['expires']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['expires']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['expires']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['expires']['alter']['external'] = 0;
  $handler->display->display_options['fields']['expires']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['expires']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['expires']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['expires']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['expires']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['expires']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['expires']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['expires']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['expires']['alter']['html'] = 0;
  $handler->display->display_options['fields']['expires']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['expires']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['expires']['hide_empty'] = 0;
  $handler->display->display_options['fields']['expires']['empty_zero'] = 0;
  $handler->display->display_options['fields']['expires']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['expires']['date_format'] = 'custom';
  $handler->display->display_options['fields']['expires']['custom_date_format'] = 'm/d/Y g:i a';
  /* Field: Budget: Repeat Every */
  $handler->display->display_options['fields']['repeat_every']['id'] = 'repeat_every';
  $handler->display->display_options['fields']['repeat_every']['table'] = 'ledger_budget';
  $handler->display->display_options['fields']['repeat_every']['field'] = 'repeat_every';
  $handler->display->display_options['fields']['repeat_every']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['repeat_every']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['repeat_every']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['repeat_every']['alter']['external'] = 0;
  $handler->display->display_options['fields']['repeat_every']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['repeat_every']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['repeat_every']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['repeat_every']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['repeat_every']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['repeat_every']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['repeat_every']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['repeat_every']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['repeat_every']['alter']['html'] = 0;
  $handler->display->display_options['fields']['repeat_every']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['repeat_every']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['repeat_every']['hide_empty'] = 0;
  $handler->display->display_options['fields']['repeat_every']['empty_zero'] = 0;
  $handler->display->display_options['fields']['repeat_every']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['repeat_every']['format_plural'] = 0;
  $handler->display->display_options['fields']['repeat_every']['suffix'] = ' ';
  /* Field: Budget: Repeat Unit */
  $handler->display->display_options['fields']['repeat_unit']['id'] = 'repeat_unit';
  $handler->display->display_options['fields']['repeat_unit']['table'] = 'ledger_budget';
  $handler->display->display_options['fields']['repeat_unit']['field'] = 'repeat_unit';
  $handler->display->display_options['fields']['repeat_unit']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['repeat_unit']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['repeat_unit']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['repeat_unit']['alter']['external'] = 0;
  $handler->display->display_options['fields']['repeat_unit']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['repeat_unit']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['repeat_unit']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['repeat_unit']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['repeat_unit']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['repeat_unit']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['repeat_unit']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['repeat_unit']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['repeat_unit']['alter']['html'] = 0;
  $handler->display->display_options['fields']['repeat_unit']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['repeat_unit']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['repeat_unit']['hide_empty'] = 0;
  $handler->display->display_options['fields']['repeat_unit']['empty_zero'] = 0;
  $handler->display->display_options['fields']['repeat_unit']['hide_alter_empty'] = 1;
  /* Field: Budget: Description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'ledger_budget';
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
  $handler->display->display_options['fields']['description']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['description']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['description']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['description']['alter']['html'] = 0;
  $handler->display->display_options['fields']['description']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['description']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['description']['hide_empty'] = 0;
  $handler->display->display_options['fields']['description']['empty_zero'] = 0;
  $handler->display->display_options['fields']['description']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['description']['link_to_budget'] = 'view';
  /* Field: Budget: Operations */
  $handler->display->display_options['fields']['budget_ops']['id'] = 'budget_ops';
  $handler->display->display_options['fields']['budget_ops']['table'] = 'ledger_budget';
  $handler->display->display_options['fields']['budget_ops']['field'] = 'budget_ops';
  $handler->display->display_options['fields']['budget_ops']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['budget_ops']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['budget_ops']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['budget_ops']['alter']['external'] = 0;
  $handler->display->display_options['fields']['budget_ops']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['budget_ops']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['budget_ops']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['budget_ops']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['budget_ops']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['budget_ops']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['budget_ops']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['budget_ops']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['budget_ops']['alter']['html'] = 0;
  $handler->display->display_options['fields']['budget_ops']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['budget_ops']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['budget_ops']['hide_empty'] = 0;
  $handler->display->display_options['fields']['budget_ops']['empty_zero'] = 0;
  $handler->display->display_options['fields']['budget_ops']['hide_alter_empty'] = 1;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
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