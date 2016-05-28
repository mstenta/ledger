<?php

/**
 * @file
 * Contains ledger.page.inc.
 *
 * Page callback for Ledger entities.
 */

use Drupal\Core\Render\Element;
use Drupal\Core\Link;
use Drupal\Core\Url;

/**
 * Prepares variables for Ledger templates.
 *
 * Default template: ledger.html.twig.
 *
 * @param array $variables
 *   An associative array containing:
 *   - elements: An associative array containing the user information and any
 *   - attributes: HTML attributes for the containing element.
 */
function template_preprocess_ledger(array &$variables) {
  // Fetch Ledger Entity Object.
  $ledger = $variables['elements']['#ledger'];

  // Helpful $content variable for templates.
  foreach (Element::children($variables['elements']) as $key) {
    $variables['content'][$key] = $variables['elements'][$key];
  }
}
