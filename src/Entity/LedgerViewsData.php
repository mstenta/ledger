<?php

namespace Drupal\ledger\Entity;

use Drupal\views\EntityViewsData;
use Drupal\views\EntityViewsDataInterface;

/**
 * Provides Views data for Ledger entities.
 */
class LedgerViewsData extends EntityViewsData implements EntityViewsDataInterface {

  /**
   * {@inheritdoc}
   */
  public function getViewsData() {
    $data = parent::getViewsData();

    $data['ledger']['table']['base'] = array(
      'field' => 'id',
      'title' => $this->t('Ledger'),
      'help' => $this->t('The Ledger ID.'),
    );

    return $data;
  }

}
