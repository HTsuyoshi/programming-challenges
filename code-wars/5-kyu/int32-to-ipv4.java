public static String longToIP(long ip) {
    String output = "";
    for (int i = 3; i >= 0; i--) {
        long aux = ip >> i * 8;
        if ((byte) aux < 0)
            output += Byte.toUnsignedInt((byte) aux);
        else
            output += (byte) aux;
        if (i != 0)
            output += ".";
    }
    return output;
}
