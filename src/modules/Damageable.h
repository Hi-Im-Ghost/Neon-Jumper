#ifndef TREES_JSON_DAMAGEABLE_H
#define TREES_JSON_DAMAGEABLE_H

 /**
  * @class Przedstawia obiekt, który może przyjąć obrażenia
  */
class Damageable {
private:
    /// Aktualna ilość punktów życia obiektu
    int hp;
    /// Maksymalna ilość punktów życia obiektu
    int maxHP;
    /// Określa, czy obiekt może przyjąć obrażenia
    bool _bIsInvincible = false;
    /// Częstotliwość z jaką możliwe jest otrzymywanie obrażeń
    float invTime;

protected:
    /** Odświeża wartość licznika, który określa za częstotliwość z jaką obiekt może otrzymywać obrażenia
     * @param deltaTime czas pomiędzy klatkami aplikacji
     */
    void updateInvincibilityTimer(float deltaTime);

public:
    /** Powoduje odjęcie punktów życia o wartość damage
     * @param damage wartość obrażeń do zadania
     */
    void takeDamage(int damage);
    /** Ustawia ilość maksymalnych punktów życia
     * @param newMax nowa wartość maksymalna punktów życia
     */
    void setMaxHP(unsigned newMax);
    /** Pozwala uzyskać ilość maksymalnych punktów życia
     * @return obecna ilość maksymalnych punktów życia
     */
    int getMaxHP() const;
    /** Ustawia ilość punktów życia
     * @param newHP nowa wartość punktów życia
     */
    void setHP(unsigned newHP);
    /** Pozwala uzyskać aktualną ilość punktów życia
     * @return obecna wartość punktów życia
     */
    int getHP() const;
    /** Pozwala sprawdzić, czy możliwe jest przyjęcie obrażeń
     * @return wartość bool określająca, czy gracz jest nieśmiertelny
     */
    bool getIsInvincible() const {return _bIsInvincible;}
    /** Pozwala sprawdzić, czy ilość punktów życia obiektu wynosi 0
     * @return wartość bool określająca, czy punkty życia gracza zeszły do zera
     */
    bool isDead();
};


#endif //TREES_JSON_DAMAGEABLE_H
