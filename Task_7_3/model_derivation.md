# Derivation of The Kinematic Model

## Finding $Vx$, $Vy$ and Omega

- In x-axis direction
    - $Vx = -V1*sin(φ)-V2*cos(30+φ)+V3*cos(30-φ)$

- In y-axis direction
    - $Vy = V1*cos(φ)-V2*sin(30+φ)-V3*sin(30-φ)$

- Omega
    - $ω = 5*(V1+V2+V3)$

---

## In Matrix Form

$$
AX=B
$$

| $Vx$ |            
| --- |                                               
| $Vy$ |      
| $ω$ |                  

 $=$ 

| $-sin(φ)$ | $-cos(30+φ)$ | $cos(30-φ)$ |
| --- | --- | --- |
| $cos(φ)$ | $-sin(30+φ)$ | $-sin(30-φ)$ |
| $5$ | $5$ | $5$ |

| $V1$ |
| --- |
| $V2$ |
| $V3$ |

---

Now we can give any value to the variable $φ$, substitute with the desired $Vx$, $Vy$ and ω,  obtain the inverse matrix of  $A$, and calculate the required speed for each motor $V1$, $V2$ and $V3$.

## Example

- Let $φ = 60⁰$

| $Vx$ |
| --- |
| $Vy$ |
| $ω$ |

$=$

| $-√(3)/2$ | $0$ | $√(3)/2$ |
| --- | --- | --- |
| $1/2$ | $-1$ | $1/2$ |
| $5$ | $5$ | $5$ |

| $V1$ |
| --- |
| $V2$ |
| $V3$ |
- Let’s Solve for Matrix $X$

| $V1$ |
| --- |
| $V2$ |
| $V3$ |

$=$

| $-√(3)/3$ | $1/3$ | $1/15$ |
| --- | --- | --- |
| $0$ | $-2/3$ | $1/15$ |
| $√(3)/3$ | $1/3$ | $1/15$ |

| $Vx$ |
| --- |
| $Vy$ |
| $ω$ |
