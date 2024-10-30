# Fractal Renderer
<a href="#"><img width="850" align="center" src="https://github.com/user-attachments/assets/c924dcd0-50d9-48e5-8b41-eb9dbe960a8f"></a>

## Sobre el Proyecto

Este proyecto contiene una recreación visual de los fractales de **Mandelbrot** y **Julia**. Ambos fractales se generan aplicando fórmulas complejas que calculan si un punto pertenece o no a un conjunto, dependiendo del número de iteraciones necesarias para divergir o mantenerse en un límite. 

<table>
  <tr>
    <td align="center"> 🐚 Conjunto de Julia</td>
    <td align="center"> 🦚 Conjunto de Mandelbrot</td>
  </tr>
  <tr>
    <td>
      <a><img width="450" src="https://github.com/user-attachments/assets/e1891c98-88aa-4146-b188-247fb6a16b07"></a><br><br>
      El conjunto de Julia es similar al de Mandelbrot pero depende de una constante específica. Esto permite observar variaciones únicas de los fractales según el valor de dicha constante, generando patrones diversos e igualmente complejos.<br>
  </td>
  <td>
      <a><img width="400" src="https://github.com/user-attachments/assets/cb4f3769-7ce9-4a67-ae56-aafe8dfb9dc5"></a><br><br>
      El conjunto de Mandelbrot se genera al iterar una función cuadrática compleja sobre cada punto en el plano complejo y verificar su divergencia. Los puntos que no divergen permanecen en el conjunto, formando una estructura con un borde intrincado e infinito.
  </td>
  </tr>
</table>

## Modo de Uso

Para compilar y ejecutar el proyecto en Linux, asegúrate de tener las siguientes dependencias instaladas, necesarias para **MiniLibX**:

```bash
sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev
```
Una vez instaladas las dependencias ejecuta el comando siguiente con las opciones disponibles que te aparecerá:
```bash
make && ./fractol
```
<a><img align="center" width="500" src="https://github.com/user-attachments/assets/cd649bc9-b5a8-4a10-9bd6-b48bbfa2415b"></a><br>
