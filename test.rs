use std::io::{self, BufRead};

fn main() {
    // Obtener la longitud de la contraseña
    let stdin = io::stdin();
    let mut input = String::new();
    print!("Ingrese la longitud de la contraseña: ");
    io::stdout().flush().unwrap();
    stdin.lock().read_line(&mut input).unwrap();
    
    let length: usize = input.trim().parse().unwrap();

    // Generar la contraseña
    let chars: &[u8] = b"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    let mut password = vec![0; length];
    let mut rng = rand::thread_rng();

    for i in 0..length {
        let char_index = rng.gen_range(0..chars.len());
        password[i] = chars[char_index];
    }

    // Imprimir la contraseña generada
    println!("Contraseña generada: {}", String::from_utf8_lossy(&password));
}
