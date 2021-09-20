<?php

namespace Drupal\ledger_ledger;

use Drupal\Core\Entity\EntityInterface;
use Drupal\Core\Entity\EntityViewBuilder;

/**
 * Provides a view controller for a ledger entity type.
 */
class LedgerViewBuilder extends EntityViewBuilder {

  /**
   * {@inheritdoc}
   */
  protected function getBuildDefaults(EntityInterface $entity, $view_mode) {
    $build = parent::getBuildDefaults($entity, $view_mode);
    // The ledger has no entity template itself.
    unset($build['#theme']);
    return $build;
  }

}
