# Fractal Renderer
<a href="#"><img width="850" align="center" src="https://github.com/user-attachments/assets/c924dcd0-50d9-48e5-8b41-eb9dbe960a8f"></a>

## About the project

This project contains a visual recreation of the Mandelbrot and Julia fractals. Both fractals are generated by applying complex formulas that calculate whether or not a point belongs to a set, depending on the number of iterations needed to diverge or stay on a boundary.

<table>
  <tr>
    <td align="center"> 🐚 Julia Set </td>
    <td align="center"> 🦚 Mandelbrot Set </td>
  </tr>
  <tr>
    <td>
      <a><img width="450" src="https://github.com/user-attachments/assets/e1891c98-88aa-4146-b188-247fb6a16b07"></a><br><br>
      The Julia set is similar to the Mandelbrot set but depends on a specific constant. This allows us to observe unique variations of the fractals depending on the value of that constant, generating diverse and equally complex patterns.<br>
  </td>
  <td>
      <a><img width="400" src="https://github.com/user-attachments/assets/cb4f3769-7ce9-4a67-ae56-aafe8dfb9dc5"></a><br><br>
     The Mandelbrot set is generated by iterating a complex quadratic function over each point in the complex plane and checking its divergence. Points that do not diverge remain in the set, forming a structure with an intricate and infinite edge.
  </td>
  </tr>
</table>

## How to use

To compile and run the project on Linux, make sure you have the following dependencies installed, which are required for **MiniLibX**:

```bash
sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev
```
Once the dependencies have been installed, run the following command with the available options that will appear:
```bash
make && ./fractol julia -0.768 0.183
```
<p align="center"><img width="500" src="https://github.com/user-attachments/assets/3bdb660f-5a15-4065-9e75-da7bae6ac852"></p><br>
<p align="center"><img width="500" src="https://github.com/user-attachments/assets/cd649bc9-b5a8-4a10-9bd6-b48bbfa2415b"></p><br>

After this, you can enjoy the infinite effect of the fractals and change the colours. Have fun ! 🙃 

## Grade
<img width="199" alt="Grade_fract-ol_42" src="https://github.com/user-attachments/assets/da68c7b4-9a12-46cd-b671-98015e04fd3e">

