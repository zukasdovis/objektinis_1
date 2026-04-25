# Studentas v1.2

C++ programa skirta studentų duomenų valdymui.

---

## Rule of Five metodai

| Metodas | Sintaksė | Paskirtis |
|---|---|---|
| Default konstruktorius | `Studentas()` | Sukuria tuščią objektą |
| Copy konstruktorius | `Studentas(const Studentas& a)` | Kuriama objekto kopija |
| Copy priskyrimo operatorius | `Studentas& operator=(const Studentas& a)` | Objekto kopijos priskyrimas — `b = a` |
| Move konstruktorius | `Studentas(Studentas&& a)` | Objekto perėmimas — `Studentas b = std::move(a)` |
| Move priskyrimo operatorius | `Studentas& operator=(Studentas&& a)` | Objekto perėmimas — `b = std::move(a)` |
| Destruktorius | `~Studentas()` | Objekto sunaikinimas (veikia automatiškai) |

---

## Įvesties/Išvesties operatoriai

| Operatorius | Sintaksė | Paskirtis |
|---|---|---|
| `operator>>` | `std::istream& operator>>(std::istream& is, Studentas& s)` | Nuskaito duomenis iš srauto į objektą |
| `operator<<` | `std::ostream& operator<<(std::ostream& os, const Studentas& s)` | Išveda objekto duomenis į srautą |

