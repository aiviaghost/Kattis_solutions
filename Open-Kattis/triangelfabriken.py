angles = [int(input()) for _ in range(3)]

print("Ratvinklig Triangel" if 90 in angles else "Spetsig Triangel" if max(angles) < 90 else "Trubbig Triangel")
