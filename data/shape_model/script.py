input_path = "sphere_invertida.obj"
output_path = "sphere_invertida_normais.obj"

with open(input_path, "r") as fin, open(output_path, "w") as fout:
    for line in fin:
        if line.startswith("vn "):
            parts = line.strip().split()
            # Inverte cada componente da normal
            x, y, z = map(float, parts[1:4])
            fout.write(f"vn {-x} {-y} {-z}\n")
        else:
            fout.write(line)