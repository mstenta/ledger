<?php

/**
 * @file
 * Ledger Account Entry UI theme functions
 */

/**
 * Theme function for the ledger account entry manager.
 */
function theme_ledger_account_entry_manager($variables) {

  // Start with an empty output.
  $output = '';

  // Isolate the form array from the variables.
  $form = $variables['form'];

  // Build a table for the account entries.
  $table = array(
    'header' => array(
      t(''),
      t('Description'),
      t('Account'),
      t('Increase'),
      t('Decrease'),
    ),
    'rows' => array(),
  );

  // Add a row for each account entry.
  if (!empty($form['rows'])) {
    foreach (element_children($form['rows']) as $key) {
      $table['rows'][] = array(
        drupal_render($form['rows'][$key]['select']),
        drupal_render($form['rows'][$key]['description']),
        drupal_render($form['rows'][$key]['aid']),
        drupal_render($form['rows'][$key]['in']),
        drupal_render($form['rows'][$key]['out']),
      );
    }

    // Render the table.
    $output .= theme('table', $table);
  }

  // If there aren't any account entries, display some empty text.
  else {
    $output .= '<p>(none)</p>';
  }

  // Render the rest of the form.
  $output .= drupal_render_children($form);

  return $output;
}