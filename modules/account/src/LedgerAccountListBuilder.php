<?php

namespace Drupal\ledger_account;

use Drupal\Core\Entity\EntityInterface;
use Drupal\Core\Entity\EntityListBuilder;
use Drupal\Core\Routing\LinkGeneratorTrait;
use Drupal\Core\Url;

/**
 * Defines a class to build a listing of Ledger Account entities.
 *
 * @ingroup ledger_account
 */
class LedgerAccountListBuilder extends EntityListBuilder {

  use LinkGeneratorTrait;

  /**
   * {@inheritdoc}
   */
  public function buildHeader() {
    $header['id'] = $this->t('Ledger Account ID');
    $header['name'] = $this->t('Name');
    return $header + parent::buildHeader();
  }

  /**
   * {@inheritdoc}
   */
  public function buildRow(EntityInterface $entity) {
    /* @var $entity \Drupal\ledger_account\Entity\LedgerAccount */
    $row['id'] = $entity->id();
    $row['name'] = $this->l(
      $entity->label(),
      new Url(
        'entity.ledger_account.edit_form', array(
          'ledger_account' => $entity->id(),
        )
      )
    );
    return $row + parent::buildRow($entity);
  }

}
