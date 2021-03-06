<?php

namespace Drupal\ledger_account\Entity;

use Drupal\Core\Entity\EntityStorageInterface;
use Drupal\Core\Field\BaseFieldDefinition;
use Drupal\Core\Entity\ContentEntityBase;
use Drupal\Core\Entity\EntityChangedTrait;
use Drupal\Core\Entity\EntityTypeInterface;
use Drupal\ledger\LedgerInterface;
use Drupal\ledger_account\LedgerAccountInterface;
use Drupal\user\UserInterface;

/**
 * Defines the Ledger Account entity.
 *
 * @ingroup ledger_account
 *
 * @ContentEntityType(
 *   id = "ledger_account",
 *   label = @Translation("Ledger Account"),
 *   bundle_label = @Translation("Ledger Account type"),
 *   handlers = {
 *     "view_builder" = "Drupal\Core\Entity\EntityViewBuilder",
 *     "list_builder" = "Drupal\ledger_account\LedgerAccountListBuilder",
 *     "views_data" = "Drupal\ledger_account\Entity\LedgerAccountViewsData",
 *
 *     "form" = {
 *       "default" = "Drupal\ledger_account\Form\LedgerAccountForm",
 *       "add" = "Drupal\ledger_account\Form\LedgerAccountForm",
 *       "edit" = "Drupal\ledger_account\Form\LedgerAccountForm",
 *       "delete" = "Drupal\ledger_account\Form\LedgerAccountDeleteForm",
 *     },
 *     "access" = "Drupal\ledger_account\LedgerAccountAccessControlHandler",
 *     "route_provider" = {
 *       "html" = "Drupal\ledger_account\LedgerAccountHtmlRouteProvider",
 *     },
 *   },
 *   base_table = "ledger_account",
 *   admin_permission = "administer ledger account entities",
 *   entity_keys = {
 *     "id" = "id",
 *     "bundle" = "type",
 *     "label" = "name",
 *     "parent" = "parent",
 *     "ledger" = "ledger",
 *     "uuid" = "uuid",
 *     "uid" = "user_id",
 *     "langcode" = "langcode",
 *   },
 *   links = {
 *     "canonical" = "/ledger/account/{ledger_account}",
 *     "add-form" = "/ledger/account/add",
 *     "edit-form" = "/ledger/account/{ledger_account}/edit",
 *     "delete-form" = "/ledger/account/{ledger_account}/delete",
 *     "collection" = "/ledger/account",
 *   },
 *   bundle_entity_type = "ledger_account_type",
 *   field_ui_base_route = "entity.ledger_account_type.edit_form"
 * )
 */
class LedgerAccount extends ContentEntityBase implements LedgerAccountInterface {

  use EntityChangedTrait;

  /**
   * {@inheritdoc}
   */
  public static function preCreate(EntityStorageInterface $storage_controller, array &$values) {
    parent::preCreate($storage_controller, $values);
    $values += array(
      'user_id' => \Drupal::currentUser()->id(),
    );
  }

  /**
   * {@inheritdoc}
   */
  public function getType() {
    return $this->bundle();
  }

  /**
   * {@inheritdoc}
   */
  public function getName() {
    return $this->get('name')->value;
  }

  /**
   * {@inheritdoc}
   */
  public function setName($name) {
    $this->set('name', $name);
    return $this;
  }

  /**
   * {@inheritdoc}
   */
  public function getCreatedTime() {
    return $this->get('created')->value;
  }

  /**
   * {@inheritdoc}
   */
  public function setCreatedTime($timestamp) {
    $this->set('created', $timestamp);
    return $this;
  }

  /**
   * {@inheritdoc}
   */
  public function getOwner() {
    return $this->get('user_id')->entity;
  }

  /**
   * {@inheritdoc}
   */
  public function getOwnerId() {
    return $this->get('user_id')->target_id;
  }

  /**
   * {@inheritdoc}
   */
  public function setOwnerId($uid) {
    $this->set('user_id', $uid);
    return $this;
  }

  /**
   * {@inheritdoc}
   */
  public function setOwner(UserInterface $account) {
    $this->set('user_id', $account->id());
    return $this;
  }

  /**
   * {@inheritdoc}
   */
  public function getParent() {
    return $this->get('parent')->entity;
  }

  /**
   * {@inheritdoc}
   */
  public function setParent(LedgerAccountInterface $account) {
    $this->set('parent', $account->id());
    return $this;
  }

  /**
   * {@inheritdoc}
   */
  public function getParentId() {
    return $this->get('parent')->target_id;
  }

  /**
   * {@inheritdoc}
   */
  public function setParentId($id) {
    $this->set('parent', $id);
    return $this;
  }

  /**
   * {@inheritdoc}
   */
  public function getLedger() {
    return $this->get('ledger')->entity;
  }

  /**
   * {@inheritdoc}
   */
  public function setLedger(LedgerInterface $ledger) {
    $this->set('ledger', $ledger->id());
    return $this;
  }

  /**
   * {@inheritdoc}
   */
  public function getLedgerId() {
    return $this->get('ledger')->target_id;
  }

  /**
   * {@inheritdoc}
   */
  public function setLedgerId($id) {
    $this->set('ledger', $id);
    return $this;
  }

  /**
   * {@inheritdoc}
   */
  public static function baseFieldDefinitions(EntityTypeInterface $entity_type) {
    $fields['id'] = BaseFieldDefinition::create('integer')
      ->setLabel(t('ID'))
      ->setDescription(t('The ID of the Ledger Account entity.'))
      ->setReadOnly(TRUE);
    $fields['type'] = BaseFieldDefinition::create('entity_reference')
      ->setLabel(t('Type'))
      ->setDescription(t('The Ledger Account type/bundle.'))
      ->setSetting('target_type', 'ledger_account_type')
      ->setRequired(TRUE);
    $fields['uuid'] = BaseFieldDefinition::create('uuid')
      ->setLabel(t('UUID'))
      ->setDescription(t('The UUID of the Ledger Account entity.'))
      ->setReadOnly(TRUE);

    $fields['user_id'] = BaseFieldDefinition::create('entity_reference')
      ->setLabel(t('Owner'))
      ->setDescription(t('The user ID of the account owner.'))
      ->setRequired(TRUE)
      ->setRevisionable(TRUE)
      ->setSetting('target_type', 'user')
      ->setSetting('handler', 'default')
      ->setDefaultValueCallback('Drupal\ledger\Entity\Ledger::getCurrentUserId')
      ->setTranslatable(TRUE)
      ->setDisplayOptions('view', array(
        'label' => 'hidden',
        'type' => 'author',
        'weight' => 0,
      ))
      ->setDisplayOptions('form', array(
        'type' => 'entity_reference_autocomplete',
        'weight' => 5,
        'settings' => array(
          'match_operator' => 'CONTAINS',
          'size' => '60',
          'autocomplete_type' => 'tags',
          'placeholder' => '',
        ),
      ))
      ->setDisplayConfigurable('form', TRUE)
      ->setDisplayConfigurable('view', TRUE);

    $fields['name'] = BaseFieldDefinition::create('string')
      ->setLabel(t('Name'))
      ->setRequired(TRUE)
      ->setDescription(t('The name of the account.'))
      ->setSettings(array(
        'max_length' => 50,
        'text_processing' => 0,
      ))
      ->setDefaultValue('')
      ->setDisplayOptions('view', array(
        'label' => 'hidden',
        'type' => 'string',
        'weight' => -4,
      ))
      ->setDisplayOptions('form', array(
        'type' => 'string_textfield',
        'weight' => -4,
      ))
      ->setDisplayConfigurable('form', TRUE)
      ->setDisplayConfigurable('view', TRUE);

    $fields['parent'] = BaseFieldDefinition::create('entity_reference')
      ->setLabel(t('Parent Account'))
      ->setDescription(t('The parent of this account (optional).'))
      ->setRevisionable(TRUE)
      ->setSetting('target_type', 'ledger_account')
      ->setSetting('handler', 'default')
      ->setDefaultValue('')
      ->setTranslatable(TRUE)
      ->setDisplayOptions('view', array(
        'label' => 'above',
        'type' => 'string',
        'weight' => -2,
      ))
      ->setDisplayOptions('form', array(
        'type' => 'entity_reference_autocomplete',
        'weight' => -2,
        'settings' => array(
          'match_operator' => 'CONTAINS',
          'size' => '60',
          'autocomplete_type' => 'tags',
          'placeholder' => '',
        ),
      ))
      ->setDisplayConfigurable('form', TRUE)
      ->setDisplayConfigurable('view', TRUE);

    $fields['ledger'] = BaseFieldDefinition::create('entity_reference')
      ->setLabel(t('Ledger'))
      ->setDescription(t('The Ledger that this account is in.'))
      ->setRequired(TRUE)
      ->setRevisionable(TRUE)
      ->setSetting('target_type', 'ledger')
      ->setSetting('handler', 'default')
      ->setDefaultValue('')
      ->setTranslatable(TRUE)
      ->setDisplayOptions('view', array(
        'label' => 'above',
        'type' => 'string',
        'weight' => 0,
      ))
      ->setDisplayOptions('form', array(
        'type' => 'entity_reference_autocomplete',
        'weight' => 0,
        'settings' => array(
          'match_operator' => 'CONTAINS',
          'size' => '60',
          'autocomplete_type' => 'tags',
          'placeholder' => '',
        ),
      ))
      ->setDisplayConfigurable('form', TRUE)
      ->setDisplayConfigurable('view', TRUE);

    $fields['langcode'] = BaseFieldDefinition::create('language')
      ->setLabel(t('Language code'))
      ->setDescription(t('The language code for the account.'))
      ->setDisplayOptions('form', array(
        'type' => 'language_select',
        'weight' => 10,
      ))
      ->setDisplayConfigurable('form', TRUE);

    $fields['created'] = BaseFieldDefinition::create('created')
      ->setLabel(t('Created'))
      ->setDescription(t('The time that the account entity was created.'));

    $fields['changed'] = BaseFieldDefinition::create('changed')
      ->setLabel(t('Changed'))
      ->setDescription(t('The time that the account entity was last edited.'));

    return $fields;
  }

}
