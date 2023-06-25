const std = @import("std");

pub fn main() !void {
    // Obtener la longitud de la contraseña
    const stdin = std.io.getStdIn().reader();
    try std.io.getStdOut().print("Ingrese la longitud de la contraseña: ");
    var input: [50]u8 = undefined;
    const len = try stdin.readLine(input[0..]) |std.io.EOF| {
        // Error al leer la entrada
        return error.PrematureEof;
    }.len;

    var length: usize = 0;
    try std.mem.parseInt(len, input[0..], &length);

    // Generar la contraseña
    const chars: [62]u8 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    var password: [100]u8 = undefined;
    var rng = std.rand.DefaultPrng.init(std.time.milliTimestamp());

    for (std.math.abs(length) + 1) |i| {
        const charIndex = rng.nextLessThan(std.len(chars));
        password[i] = chars[charIndex];
    }
    password[length] = 0;

    // Imprimir la contraseña generada
    const stdout = std.io.getStdOut().writer();
    try stdout.print("Contraseña generada: {}\n", .{password});
}
