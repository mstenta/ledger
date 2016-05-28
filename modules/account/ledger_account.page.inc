<?php

/**
 * @file
 * Contains ledger_account.page.inc.
 *
 * Page callback for Ledger Account entities.
 */

use Drupal\Core\Render\Element;
use Drupal\Core\Link;
use Drupal\Core\Url;

/**
 * Prepares variables for Ledger Account templates.
 *
 * Default template: ledger_account.html.twig.
 *
 * @param array $variables
 *   An associative array containing:
 *   - elements: An associative array containing the user information and any
 *   - attributes: HTML attributes for the containing element.
 */
function template_preprocess_ledger_account(array &$variables) {
  // Fetch LedgerAccount Entity Object.
  $ledger_account = $variables['elements']['#ledger_account'];

  // Helpful $content variable for templates.
  foreach (Element::children($variables['elements']) as $key) {
    $variables['content'][$key] = $variables['elements'][$key];
  }
}
